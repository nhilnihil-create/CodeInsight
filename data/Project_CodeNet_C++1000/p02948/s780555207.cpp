#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<n;i++)
#define rrep(i,n) for(ll i=n-1;i>=0;i--)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;

int main(){
    ll N,M; cin>>N>>M;
    ll ans=0;
    priority_queue<P,vector<P>,greater<P> > que;
    priority_queue<ll,vector<ll> > caneat;
    vector<ll> A(N+1,0);
    vector<ll> B(N+1,0);
    rep1(i,N){
        cin>>A[i]>>B[i];
        que.push(mp(A[i],B[i]));
    }
    rep1(i,M){
        while(!que.empty()){
            if(que.top().a <= i){
                caneat.push(que.top().b);
                que.pop();
            }
            else break;
        }
        
        if(!caneat.empty()){
            ans+=caneat.top();
            caneat.pop();
        }
    }
    cout<<ans;
}
