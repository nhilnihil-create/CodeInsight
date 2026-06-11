#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using ll=long long;
const int mod=1e9+7;
const int N = 2e5+5;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> orderset; 

vector<ll> sieve(ll n) {     
    bool prim[n+1]; 
    memset(prim, true, sizeof(prim)); 
  
    for (ll p=2; p*p<=n; p++) {
        if (prim[p] == true) { 
            for (ll i=p*p; i<=n; i += p) 
                prim[i] = false; 
        } 
    }
    vector<ll>vec;
    for(int i=2;i<=n;i++){
        if(prim[i]){
            vec.push_back((ll)i);
        }
        
    }
    return vec;
}

int check(int a,int b,int c,int d,int e,int f){
    if(a==b&&c==d&&e==f) return 1;
    return 0;
}

void solve(){
  int n;
  cin>>n;
  vector<pair<int,int>>vec(n);
  for (int i = 0; i < n; i++) {
      cin>>vec[i].first>>vec[i].second;
  }
  for (int i = 0; i <n-2 ; i++) {
      if(check(vec[i].first,vec[i].second,vec[i+1].first,vec[i+1].second,vec[i+2].first,vec[i+2].second)){
          cout<<"Yes\n";
          return;
      }
  }
  cout<<"No\n";
   
  
    
}

int main(){
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif*/
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int T=1;
        //cin>>T;
        while(T--){
          solve();
        }
        return 0;
        
}