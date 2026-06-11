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
    vector<ll> d(N);
    REP(i,N){ cin >> d[i]; }

    ll total = 0;
    for(int i = 0 ; i < N; i++ ){
        for( int j = i+1; j < N; j++ ){
           total += d[i] * d[j];
        }
    }

    cout << total << endl;
}
