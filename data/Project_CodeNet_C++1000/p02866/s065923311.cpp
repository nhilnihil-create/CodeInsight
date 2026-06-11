#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll power(ll A,ll B,ll M){
    if(B==0){
        return 1;
    }
    else if(B%2==0){
        ll s=power(A,B/2,M);
        return (s*s)%M;
    }
    else{
        return ((A%M)*power(A,B-1,M))%M;
    }
}

ll MOD=998244353;

int main(){
    ll N;
    cin>>N;
    Graph G(N);
    bool flag=true;
    rep(i,N){
        int a;
        cin>>a;
        if(i==0){
            if(a!=0){
                flag=false;
            }
        }
        if(i!=0){
            if(a==0){
                flag=false;
            }
        }
        G[a].push_back(i+1);
    }
    vector<ll>GN(N);
    rep(i,N){
        GN[i]=G[i].size();
    }
    for(int i=1;i<N;i++){
        if(GN[i-1]==0&&GN[i]!=0){
            flag=false;
        }
    }
    if(flag){
        //前の枝にどのようにくっつけるか
        ll Ans=1;
        for(int i=2;i<N;i++){
            ll P=GN[i];
            if(P==0){
                break;
            }
            ll Q=GN[i-1];
            Ans=(Ans*power(Q,P,MOD))%MOD;
        }       
        cout<<Ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
}

