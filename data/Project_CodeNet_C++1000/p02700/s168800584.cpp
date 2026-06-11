// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
//
//
void solve(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    int win = 0;
    while(a>0 && c>0){
        if(win)
            a -= d;
        else
            c -= b;
        win ^= 1;
    }
    cout<< (win? "Yes": "No");
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