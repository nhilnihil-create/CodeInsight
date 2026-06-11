#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll N, K;
vector<ll> A;
vector<ll> F;

bool solve(ll L){
    ll k = 0;
    REP(i,N){
        k += max(A[i] - L / F[i], 0LL);
    }

    if(k <= K)
        return true;
    else
        return false;
}

int main(){
    cin >> N >> K;

    A.resize(N);
    F.resize(N);
    REP(i,N){
        cin >> A[i];
    }
    REP(i,N){
        cin >> F[i];
    }

    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());

    ll left = -1;
    ll right = 1e18;
    //ll right = 25;
    while(right - left > 1){
        ll mid = (left + right) / 2;
        bool valid = solve(mid);
        if(valid){
            right = mid;
        }
        else{
            left = mid;
        }
    }

    ll ans = right;
    cout << ans << endl;
    return 0;
}
