#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,K,ans=0;
    cin>>N>>K;
    vector<ll> A(N);
    for(ll i=0;i<N;i++) cin>>A[i];
    for(ll i=0;i<N;i++){
        ll r=0,w=0,sum;
        for(ll j=0;j<N;j++){
            if(i<j&&A[i]<A[j]) r++;
            else if(i<j&&A[i]>A[j]) w++;
        }
        sum=K*(K+1)/2;
        sum%=MOD;
        ans+=w*sum;
        ans%=MOD;
        sum=K*(K-1)/2;
        sum%=MOD;
        ans+=r*sum;
        ans%=MOD;
    }
    cout<<ans<<endl;
}