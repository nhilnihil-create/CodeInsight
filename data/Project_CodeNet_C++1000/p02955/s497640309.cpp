#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REP2(i,s,n) for(ll i=s;i<ll(n);i++)
#define REPR(i,n) for(ll i=ll(n)-1;i>=0;i--)

int N,K;
ll ans=0;
vector<ll> V(500),T(500),S1(501),S2(501);

void print_vec(vector<ll> V,ll size){
    REP(i,size) cout<<V[i]<<" ";
    cout<<endl;
}

bool check(ll mid){
    REP(i,N) T[i]=V[i]%mid;
    sort(T.begin(),T.begin()+N);
    S1[0]=0;S2[N]=0;
    REP(i,N) S1[i+1]=S1[i]+T[i];
    REP(i,N) S2[i+1]=S2[i]+mid-T[N-i-1];
    REP2(i,1,N+1){
        ll j=N-i;
        if(S1[i]-S2[j]==0 && S1[i]<=K){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> K;
    REP(i,N) cin>> V[i];
    ll sum= accumulate(V.begin(),V.begin()+N,ll(0));
    ll i=1;

    for(ll i=1;i*i<=sum;i++)
    {
        if(sum%i==0){
            if(check(i) && i>=ans) ans=i;
            if(check(sum/i) && sum/i>=ans) ans=sum/i;
        }
    }

    cout<<ans<<endl;

    return 0;
}
