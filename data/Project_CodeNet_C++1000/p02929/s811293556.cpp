#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    string S;
    cin>>S;
    if(S.at(0)=='W' || S.at(2*N-1)=='W'){
        cout<<0<<endl;return 0;
    }
    vector<int> fro(2*N),bac(0);
    rep(i,2*N){
        if(i%2==0){
            if(S.at(i)=='B'){fro.at(i)=1;}
            else{bac.pb(i);}
        }
        else{
            if(S.at(i)=='W'){fro.at(i)=1;}
            else{bac.pb(i);}
        }
    }
    if(bac.size()!=N){
        cout<<0<<endl;return 0;
    }
    ll count=0;
    ll ans=1;
    for(int i=2*N-1;i>=0;i--){
        if(fro.at(i)){
            ans*=bac.end()-lower_bound(bac.begin(),bac.end(),i)-count;
            ans%=MOD;
            count++;
        }
    }
    rep(i,N){
        ans*=i+1;
        ans%=MOD;
    }
    cout<<ans<<endl;
}