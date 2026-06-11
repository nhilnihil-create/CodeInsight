#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main(){
  double a,b;
  cin >> a >> b;
  ll ans=0;
  if(a==1||b==1){
    cout <<"1" <<endl;
    return 0;
  }
  double calc =floor(a/2)*b;
  ans = calc;
  if(fmod(a,2) != 0){
    ans += ceil(b/2);
  }
  cout << ans <<endl;
  return 0;
}