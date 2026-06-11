#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int64_t i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    int64_t ans=0, t=1;
    rep(i,0,60){
        int64_t one=0,zero=0;
        rep(j,0,N){
            if(A.at(j)&((int64_t)1<<i)) one++;
            else zero++;
        }

        int64_t _ans=(one*zero)%MOD*t%MOD;
        ans=(ans+_ans)%MOD;
        t=(t*2)%MOD;
    }

    cout<<ans<<endl;
}