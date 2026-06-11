// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    int a, b;
    cin>>a>>b;
    for(int i = 1; i < 1100; i++){
        if(i*8/100 == a && i*10/100 == b){
            cout<<i;
            return ;
        }
    }
    cout<<"-1\n";
}
int main(){ 
        hs;
        ll t;
        t=1;
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}