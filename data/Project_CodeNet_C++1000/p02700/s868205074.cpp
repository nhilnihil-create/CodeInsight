#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int a,b,c,d;
  cin >> a >> b >> c >>d;
  int t_n = a/d,a_n = c/b;//何回耐えるか
  if(a%d !=0){
    t_n++;
  }
  if(c%b !=0){
    a_n++;
  }
  if(t_n >= a_n){
    cout << "Yes" <<endl;
  }
  else{
    cout << "No" <<endl;
  }
  return 0;
}