#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ll mod=1e9+7;
const ll MAXN = 1e7+10;


  
int spf[MAXN];

void solve(){
    
    int ans=0,n=0;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int a;cin>>a;
        if(((i+1)%2==1)&&(a&1)) ans++;
    }
    cout<<ans<<"\n";
    
    
}
  
        

int main(){
   
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout); 
    #endif */
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int T=1;
        //cin>>T;
        while(T--){
            solve();
        }
            
            
        return 0;
}
 