#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N,A,B; cin>>N>>A>>B;

    int64_t ans;
    if((B-A)%2){
        ans=min(A-1,N-B)+1;
        ans+=(B-A-1)/2;
    }else{
        ans=(B-A)/2;
    }

    cout<<ans<<endl;
}