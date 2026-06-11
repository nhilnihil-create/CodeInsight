#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int64_t> A(N);
    rep(n,0,N) cin>>A.at(n);

    int64_t ans=0;
    rep(n,0,N){
        if(n==0){
            rep(n,0,N){
                if(n%2) ans-=A.at(n);
                else ans+=A.at(n);
            }
        }else{
            ans=2*A.at(n-1)-ans;
        }

        cout<<ans<<" ";
    }

    cout<<endl;
}