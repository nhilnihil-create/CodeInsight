#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  int n;
  cin >> n;
  ll val=7;
  ll ans=1;
  while(val%n!=0){
    val=val%n;
    val= val*10+7;
    if(ans==1000001) break;
    ans++;
  }
  if(ans==1000001) ans=-1;

  cout << ans << endl; 

  return 0;
}