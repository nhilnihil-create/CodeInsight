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


void solve(){
  string s;
  cin>>s;
  s.back()=='s'?cout<<s<<"es":cout<<s<<"s";
   
  
    
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