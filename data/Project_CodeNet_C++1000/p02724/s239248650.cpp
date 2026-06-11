#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve(){
  ll ans=0;
  ll n;
  cin >> n;
  ans=(1ll*1000*(n/500))+(1ll*5*((n%500)/5));
  cout << ans << endl;
}

int main(){
  	solve();
	return 0;  
}


