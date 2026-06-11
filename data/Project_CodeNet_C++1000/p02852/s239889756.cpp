#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main(){
    ll n,m; cin>>n>>m;
    string s; cin>>s;
    vector<ll> res;
    ll loc=n;
    while(loc>0){
        bool ifpossible=false;
        for(ll i=m; i>0; i--){
            if(loc-i>=0 && s[loc-i]=='0'){
                res.push_back(i);
                loc-=i;
                ifpossible=true;
                break;
            }
        }
        if(!ifpossible){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll kaisu=res.size();
    for(ll i=kaisu-1; i>=0; i--){
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}