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
  string s;
  cin >> s;
  ll ct=0, ans=0;
  for(char x:s){
	if(x=='R')
		++ct;
	else if(x=='S'){
		ct=0;
	}	  	
	ans=max(ct, ans);
  }
  cout << ans << endl;
}  

int main(){
  solve();
  return 0;
}
