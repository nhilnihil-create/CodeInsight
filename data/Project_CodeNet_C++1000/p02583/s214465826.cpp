#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define endl "\n"
#define MOD 1000000007

vector <ll> ad[200006];
vector <ll> vis(200006,0);

ll ans=0, n, m;

void addedge(ll x, ll y){
  ad[x].push_back(y);
  ad[y].push_back(x);
}

ll dfs(ll node){
  vis[node]=1;
  ++ans;
  for(ll x:ad[node]){
    if(!vis[x]){
      dfs(x);
    }
  }
  return ans;
}

void solve(){
  ll ans=0, n;
  cin >> n;
  ll a[n];
  for(ll i=0; i<n; i++){
  	cin >> a[i];
  }
 // sort(a,a+n);
  for(ll i=0;i<n;i++){
  	for(ll j=i+1;j<n;j++){
  		for(ll k=j+1; k<n;k++){
  			if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[k]+a[j]>a[i] && a[i]!=a[j] && a[j]!=a[k] && a[k]!=a[i]	)
  				++ans;
  		}
  	}
  }
  	cout << ans << endl;
}  

int main(){
  solve();
  return 0;
}
