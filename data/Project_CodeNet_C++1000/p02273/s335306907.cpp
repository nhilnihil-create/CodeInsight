#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;

typedef struct Point{
  double x;
  double y;
}P;

void koch(P p1, P p2, int i, int n){ // 今深さi，深さnまで
  if(n == 0){
    // cout << p1.x << " " << p1.y << endl;
    printf("%.8f %.8f\n", p1.x, p1.y);
    return;
  }

  P s, u, t;
  double th = M_PI * 60.0 / 180.0; // 60度をラジアンで
  s.x = (2 * p1.x + 1 * p2.x) / 3;
  s.y = (2 * p1.y + 1 * p2.y) / 3;
  t.x = (1 * p1.x + 2 * p2.x) / 3;
  t.y = (1 * p1.y + 2 * p2.y) / 3;
  u.x = s.x + (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th);
  u.y = s.y + (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th);

  if(i < n-1){
    koch(p1, s, i+1, n);
    koch(s, u, i+1, n);
    koch(u, t, i+1, n);
    koch(t, p2, i+1, n);
  }else{
    // cout << p1.x << " " << p1.y << endl;
    // cout << s.x << " " << s.y << endl;
    // cout << u.x << " " << u.y << endl;
    // cout << t.x << " " << t.y << endl;
    printf("%.8f %.8f\n", p1.x, p1.y);
    printf("%.8f %.8f\n", s.x, s.y);
    printf("%.8f %.8f\n", u.x, u.y);
    printf("%.8f %.8f\n", t.x, t.y);
  }
  return;
}



int main(){
  int n;
  cin >> n;

  P pst = {0.0, 0.0};
  P pen = {100.0, 0.0};

  koch(pst, pen, 0, n);

  // cout << pen.x << " " << pen.y << endl;
  printf("%.8f %.8f\n", pen.x, pen.y);

  return 0;
}
