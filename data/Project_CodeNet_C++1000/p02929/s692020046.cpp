#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

const ll mod=1e9+7;
const ll inf=1ll<<60;

/*---------------------*/

ll n;
string s;
vector<bool> b;

ll kaijo(ll n){
    return n?(kaijo(n-1)*n)%mod:1;
}

int main(){
    cin>>n>>s;
    b.resize(n*2);
    if(s[0]=='W'||s[n*2-1]=='W'){
        cout<<0<<endl;
        return 0;
    }

    b[0]=1;
    FOR(i,1,n*2){
        b[i]=b[i-1]^s[i]==s[i-1];
    }

    ll num=0,ans=1;
    rep(i,n*2){
        if(b[i])num++;
        else{
            (ans*=num)%=mod;
            num--;
        }
    }

    cout<<(num?0:(ans*kaijo(n))%mod)<<endl;
}