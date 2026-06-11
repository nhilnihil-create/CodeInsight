#include <bits/stdc++.h>
using namespace std;
#define REP(asd, fgh) for(int asd = 0; asd < fgh; asd++)
#define MAX_N 200000

class RMinQ{
  public:
  int n;
  int data[MAX_N * 2 - 1];

  void init(){
    for(int i=0; i < 2 * n - 1; i++){
      data[i] = INT_MAX;
    }
  }
  void update(int i, int x){
    i += n - 1;
    data[i] = x;
    while(i > 0){
      i = (i-1) / 2;
      data[i] = min(data[i*2+1], data[i*2+2]);
    }
  }
  int query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return INT_MAX;
    if(a <= l && r <= b) return data[k];
    else{
      int vl = query(a, b, k*2+1, l, (l+r)/2);
      int vr = query(a, b, k*2+2, (l+r)/2, r);
      return min(vl, vr);
    }
  }
};

int main(void){
  int n;
  int a[MAX_N];
  RMinQ r;
  int res = INT_MIN;
  int tmp=1;
  cin >> n;
  while(1){
    if(pow(2, tmp) >= n){
      r.n = pow(2, tmp);
      break;
    }
    tmp++;
  }
  r.init();
  REP(i, n){
    cin >> a[i];
    r.update(i, a[i]);
  }





  for(int i = n-1; i >= 1; i--){
    res = max(res, a[i] - r.query(0, i, 0, 0, r.n));
  }

  cout << res << endl;

  return 0;
}