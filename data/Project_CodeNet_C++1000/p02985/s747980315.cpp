#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll factmod(ll a,ll b,ll m) {
  if(a<b)return 0;
  ll s=1;
  while(a>=b){
    s = s*a % m;
    a -= 1;
  }
  return s;
}

int main(){

  ll n,k;
  cin >> n >> k;

  vector<vector<ll>> G(n);
  // ll nokori[n]={};//各ノードにたいして、まだ色を塗っていないノードがいくつつながっているか
  for(int i=0;i<n-1;i++){
    ll a,b;
    cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
    // nokori[a-1]++;
    // nokori[b-1]++;
  }


  vector<bool> seen(n,false);//色を塗ったかどうか
  seen[0]=true;
  queue<ll> q;
  q.push(0);
  ll m=k;//0の塗り方はk通り

  while(!q.empty()){
    ll a=q.front();
    q.pop();
    ll b=0;
    for(int i=0;i<G[a].size();i++){
      if(seen[G[a][i]])continue;
      seen[G[a][i]]=true;
      q.push(G[a][i]);
      m=m*(k-(G[a].size()-b))%mod;
      b++;
    }
    if(G[a].size()+1>k){
      m*=0;
      break;
    }
  }

  cout << m << endl;



}