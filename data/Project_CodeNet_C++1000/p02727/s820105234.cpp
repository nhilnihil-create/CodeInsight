#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  
  vector<int> p(a);
  for(int i=0; i<a; i++){
    cin >> p[i];
  }
  vector<int> q(b);
  for(int i=0; i<b; i++){
    cin >> q[i];
  }
  vector<int> r(c);
  for(int i=0; i<c; i++){
    cin >> r[i];
  }
  
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  sort(r.begin(),r.end());
  
  vector<int> apple(x+y+c);
  for(int i=0; i<x; i++){
    apple[i] = p[a-x+i];
  }
  for(int i=0; i<y; i++){
    apple[x+i] = q[b-y+i];
  }
  for(int i=0; i<c; i++){
    apple[x+y+i] = r[i];
  }
  sort(apple.begin(),apple.end());
  reverse(apple.begin(),apple.end());
  long ans = 0;
  for(int i=0; i<x+y; i++){
    ans += apple[i];
  }
  cout << ans << endl;
}