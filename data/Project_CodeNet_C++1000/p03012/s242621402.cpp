#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;
    cin >> N;
    vector<ll> W(N);

    ll total = 0;
    REP(i, N){
        cin >> W[i];
        total += W[i];
    }

    ll left = 0;
    ll m = INT_MAX;
    REP(i, N-1){
       left += W[i];
       ll right = total - left;
       m = min(m, abs(right-left));
    }

    cout << m << endl;
}
