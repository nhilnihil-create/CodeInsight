#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{
    int N;
    cin >> N;
    ll K;
    cin >> K;
    vl A(N);
    in(N,A);
    
    vl S(N+1);
    S[0] = 0;
    rep(i,N) S[i+1] = S[i]+A[i];
    rep(i,N+1) S[i] -= i;
    rep(i,N+1) S[i] %= K;
    
    ll ans = 0;
    map<ll,ll> inK;
    K = min((ll)N+1,K);
    rep(i,K) inK[S[i]]++;
    
    rep(i,N){
        inK[S[i]]--;
        ans += inK[S[i]];
        
        if(i+K <= N) inK[S[i+K]]++;
    }
    out(ans);

    
    
    
    

    return 0;
}
