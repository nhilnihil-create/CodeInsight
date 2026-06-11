#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N)cin>>a.at(i);
    bool j=true;
    rep(i,N){
        if(a.at(i)!=0)j=false;
    }
    if(j){
        cout<<"Yes"<<endl;
        return 0;
    }
    if(N%3!=0){cout<<"No"<<endl;return 0;}
    sort(a.begin(),a.end());
    rep(i,N-1){
        if(i==N/3-1 || i==2*N/3-1){
            continue;
        }
        if(a.at(i)!=a.at(i+1)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    ll A,B,C;
    A=a.at(0);B=a.at(N/3);C=a.at(2*N/3);
    ll X=A;
    X^=B;X^=C;
    if(X==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}