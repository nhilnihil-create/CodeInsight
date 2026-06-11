#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int> A(N);
    rep(n,0,N) cin>>A.at(n);

    int64_t ans=1;
    vector<int> V(3,0);
    rep(i,0,N){
        int cnt=0,idx;
        rep(j,0,3){
            if(A.at(i)==V.at(j)){
                cnt++;
                idx=j;
            }
        }

        if(!cnt){
            cout<<0<<endl;
            return 0;
        }

        ans*=cnt;
        ans%=MOD;
        V.at(idx)++;
    }

    cout<<ans<<endl;
}