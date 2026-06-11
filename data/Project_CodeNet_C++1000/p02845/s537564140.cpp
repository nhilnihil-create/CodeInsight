#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=100100;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,ans=1;
    cin>>N;
    vector<ll> A(N),cnt(N,0);
    for(ll i=0;i<N;i++){
        cin>>A[i];
        cnt[A[i]]++;
        if(A[i]==0) ans*=4-cnt[A[i]];
        else ans*=cnt[A[i]-1]-cnt[A[i]]+1;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
