#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

bool time_check(int N,ll K, vector<ll> A, vector<ll> F, ll T){
    ll needs = 0;
    rep(i,N){
        ll cost = T/F[i];
        needs += max(A[N-1-i]-cost,0ll);
    }
    if(needs <= K) return true;
    else return false; 
}

void solve(int N,ll K,vector<ll>A,vector<ll> F,ll start,ll end){
    // start : impossible, end : possible
    if(end == start + 1){
        cout<<end<<endl;
        return ;
    }
    ll t = (end+start)/2;
    if(time_check(N,K,A,F,t)) solve(N,K,A,F,start,t);
    else solve(N,K,A,F,t,end);
}

int main(){
    int N;
    ll K;
    vector<ll>A,F;
    ll a,f;
    cin>>N>>K;
    ll sum = 0;
    rep(i,N){
        cin>>a;
        A.push_back(a);
        sum+=a;
    }
    if(sum<=K){
        cout<<0<<endl;
        return 0;
    }
    rep(i,N) {
        cin>>f;
        F.push_back(f);
    }
    sort(A.begin(),A.end());
    sort(F.begin(),F.end());
    // rep(i,N) cout<<A[i]<<" ";
    // cout<<endl;
    // rep(i,N) cout<<F[i]<<" ";
    // cout<<endl;
    solve(N,K,A,F,0ll,(ll)10000000000000);
    return 0;
}