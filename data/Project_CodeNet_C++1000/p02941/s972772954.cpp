#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N;
ll A[202020], B[202020];
stack<ll>S;
ll push(ll b){
    if(A[b] > B[b])return -1;
    ll a = (b + N - 1) % N;
    ll c = (b + 1) % N;
    if(B[a] < B[b] && B[b] > B[c])S.push(b);
    return 0;    
}

ll solve(){
    cin >> N;
    rep(i, N)cin >> A[i];
    rep(i, N)cin >> B[i];
    ll ans = 0;
    rep(b, N)if(push(b) < 0)return -1;
    while(!S.empty()){
        ll b = S.top();
        S.pop();
        ll a = (b + N - 1) % N;
        ll c = (b + 1) % N;
        ll diff = B[b] - A[b];
        ll sum = B[a] + B[c];
        ll tmp = diff / sum;
        B[b] -= tmp * sum;
        ans += tmp;
        if(push(a) < 0)return -1;
        if(push(c) < 0)return -1;
    }
    rep(i, N)if(A[i] != B[i])return -1;
    return ans;
}

int main(){

    cout << solve() << endl;

    return 0;
}