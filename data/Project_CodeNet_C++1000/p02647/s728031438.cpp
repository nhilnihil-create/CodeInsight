#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
constexpr ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(12);
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i,N)cin >> A[i];
    ll fin = 1;
    REP(i,K){
        fin = 1;
        vector<ll> imos(N);
        REP(l,N){
            imos[max(ll(0),l - A[l])]++;
            if(l + A[l] + 1 < N)imos[l + A[l] + 1]--;
        }
        ll im = 0;
        REP(l,N){
            im += imos[l];
            A[l] = im;
            if(A[l] != N)fin = 0;
        }
        if(fin)break;
    }
    REP(i,N)cout << A[i] << "\n";
}