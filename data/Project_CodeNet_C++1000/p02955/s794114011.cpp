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

vector<ll> divisor(ll a){
    vector<ll> ret;
    for(ll i = 1; i*i <= a; i++){
        if(a % i == 0){
            ret.push_back(i);
            if((a/i) != i)
                ret.push_back(a/i);
        }
    }

    return ret;
}

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll>  A(N);
    ll sum = 0;
    REP(i,N){
        ll a;
        cin >> a;
        sum += a;
        A[i] = a;
    }

    auto div = divisor(sum);

    ll ans = 1;
    for(auto&& x : div){
        if(x < ans) continue;
        vector<ll> B(N);
        REP(i,N) B[i] = A[i] % x;
        sort(B.begin(), B.end());

        vector<ll> down(N);
        vector<ll> up(N);

        REP(i,N){
            down[i] = B[i];
            if(i != 0) down[i] += down[i-1];
        }

        for(int i = N-1; i >= 0; i--){
            up[i] = x - B[i];
            if(i != N-1) up[i] += up[i+1];
        }

        bool valid = false;
        REP(i,N-1)
            if(down[i] == up[i+1] && down[i] <= K)
                valid = true;

        if(valid)
            chmax(ans, x);
    }

    cout << ans << endl;
    return 0;
}
