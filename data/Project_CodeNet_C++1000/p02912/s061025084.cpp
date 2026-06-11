// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll power(ll x, ll y); 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitcount(n) __builtin_popcountll(n)
#define in_edges(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){int A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"

const ll MOD = 1000000007;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    quickio
    ll n, m;
    cin >> n >> m;

    priority_queue<pair<ll, ll> >pq;
    rep(i, 0, n){
        ll inp;
        cin >> inp;
        pq.push({inp - inp/2, inp});
    }

    while(m--){
        auto p = pq.top();
        pq.pop();
        auto x = p.ss/2;
        pq.push({x - x/2, x});
    }

    ll res = 0;
    while(pq.size()) res += pq.top().ss, pq.pop();

    cout << res;
}

ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}