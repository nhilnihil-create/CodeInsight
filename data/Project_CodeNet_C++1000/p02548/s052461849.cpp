#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 1e5+5;




void solve(){
  int n;
  cin>>n;
  ll ans=0;n--;
  for (int i = 1; i <=n; ++i){
    ans+=(n/i);
  }
  cout<<ans<<'\n';
    
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int T=1;
        //cin>>T;
        while(T--){
          solve();
        }
        return 0;
        
}