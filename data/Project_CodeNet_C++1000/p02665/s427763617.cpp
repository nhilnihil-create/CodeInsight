#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int N,A[101010];

ll solve(){
    if(N==0){
        if(A[0]==1) return 1;
        else return -1;
    }

    if(A[0]!=0) return -1;

    ll tot=0;
    rep(i,N+1) tot+=A[i];

    ll cur=1;
    ll ans=1;
    for(int i=1;i<N+1;i++){
        cur*=2;
        if(cur<A[i]) return -1;
        ans+=min(cur,tot);
        cur=min(cur,tot)-A[i];
        tot-=A[i];
    }

    return ans;
}

int main(){
    cin>>N;
    rep(i,N+1) cin>>A[i];
    cout<<solve()<<endl;
}


 