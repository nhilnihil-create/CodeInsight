#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N)cin >> A[i];
    vector<ll> C(N);
    vector<ll> D(N);
    vector<ll> E(1000000);
    REPS(i,N){
        C[i-1] = A[i-1] + i;
        D[i-1] = i - A[i-1];
    }
    REP(i,N){
        if(D[i] >= 0){
            E[D[i]]++;
        }
    }
    ll answer = 0;
    REP(i,N){
        if(C[i] >= 0&&C[i] <= 800000){
            answer += E[C[i]];
        }
        if(D[i] >= 0){
            E[D[i]]--;
        }
    }
    cout << answer << "\n";
}