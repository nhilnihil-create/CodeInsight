#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,p;
    string s;
    cin >> n >> p >> s;

    vector<ll> mods(p);
    ll m=0,order=1,ans=0;
    rep(i,n){
        if(p==2){
            if((s[i]-'0')%2==0) ans+=i+1;
        }else if(p==5){
            if((s[i]-'0')%5==0) ans+=i+1;
        }else{
            m = (m + order * (s[n-1-i] - '0')) % p;
            mods[m]++;
            order = (order*10)%p;
        }
        
    }
    if(p==2 || p==5){
        print(ans);
    }else{
        mods[0]++;
        rep(i,p){
            ans += mods[i]*(mods[i]-1)/2;
        }
        print(ans);
    }
    
    return 0;
}