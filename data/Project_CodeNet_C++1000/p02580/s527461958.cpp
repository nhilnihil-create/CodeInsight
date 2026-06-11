#include<bits/stdc++.h>
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second
#define int long long
#define sz(x) (ll)(x.size())
using namespace std;


const int mod = 1e9+7;

int expo_pow(int x,int y){
 if(y == 0) return 1;
  y=y%(mod-1);
  x%=mod;
  if(y==0) y=mod-1;
  int res=1;
  while(y){
    if(y&1) res=(res*x)%mod;
    x=(x*x)%mod;
    y>>=1; 
  }
  return res;
}

ll add()
{
    return 0;
}

template <typename T, typename... Types>
T add(T var1, Types... var2){
    return (((((ll)(var1)) % mod + (ll)(add(var2...))) % mod) + mod) % mod;
}

ll mul(){
    return 1;
}

template <typename T, typename... Types>
T mul(T var1, Types... var2){
    return (((ll)(var1)) % mod * (ll)(mul(var2...))) % mod;
}

const int mx = 3e5 + 10;
int tree[4*mx];

void update(int n,int st,int end,int idx,int val){
  if(st==end){
    tree[n] += val;
    return;
  }
  int mid = (st + end)/2;
  if(idx<=mid) update(2*n,st,mid,idx,val);
  else update(2*n+1,mid+1,end,idx,val);
  tree[n] = max(tree[2*n],tree[2*n+1]);
}


void solve(){
  int h,w,m;
  cin>>h>>w>>m;
  vector<int> row[h+1];
  int col[w+1];
  
  int ans = 0;

  for(int i=0;i<m;i++){
    int p,q;
    cin>>p>>q;
    update(1,0,w,q,1);
    row[p].pb(q);
  }
  for(int i=1;i<=h;i++){
    
    for(auto u:row[i]){
      update(1,0,w,u,-1);
    }
    ans = max(ans,(int)row[i].size() + tree[1]);
    for(auto u:row[i]){
      update(1,0,w,u,1);
    }
  }
  cout<<ans<<"\n";

}


signed main(){
  fast;
  int test = 1;
  int i=1;
  while(test--){
    solve();
  }
}



