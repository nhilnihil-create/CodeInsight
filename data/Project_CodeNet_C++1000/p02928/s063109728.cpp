#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int64_t i=ini;i<n;i++)
#define _rep(i,ini,n) for(int64_t i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,K; cin>>N>>K;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    vector<int64_t> Lfall(N,0),Rfall(N,0);
    rep(i,0,N){
        rep(j,0,N){
            if(j<i && A.at(j)<A.at(i)) Lfall.at(i)++;
            if(i<j && A.at(j)<A.at(i)) Rfall.at(i)++;
        }
    }

    int64_t ans=0;
    rep(n,0,N){
        int64_t val=((K*(K-1))/2)%MOD;
        val*=(Lfall.at(n)+Rfall.at(n))%MOD;
        val%=MOD;
        val+=(K*Rfall.at(n))%MOD;
        val%=MOD;

        ans+=val;
        ans%=MOD;
    }

    cout<<ans<<endl;
}