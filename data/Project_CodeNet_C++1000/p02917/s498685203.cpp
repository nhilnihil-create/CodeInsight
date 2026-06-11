#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
ll B[105];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep(i,N-1){
    cin>>B[i];
}
ll ans=0;
rep(i,N){
    if(i==0) ans+=B[0];
    else if(i==N-1) ans+=B[N-2];
    else ans+=min(B[i-1],B[i]);
}
cout<<ans<<endl;

}
    
