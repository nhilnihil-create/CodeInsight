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
    ll n;
    cin>>n;
    string ans = "";
    while(n ){
        if(n%26 == 0){
            ans += 'z';
            n /= 26;
            --n;
        }
        else{
            ans += (char)('a'+n%26-1);
            n /= 26;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
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