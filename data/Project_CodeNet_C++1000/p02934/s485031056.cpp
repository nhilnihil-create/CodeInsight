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
    vector<double> A(N);
    double bunshi = 1.0;
    REP(i, N){
        cin >> A[i];
        bunshi *= A[i];
    }

    double bunbo = 0.0;
    REP(i, N ){
       bunbo += bunshi/A[i];
    }

    cout << bunshi/bunbo << endl;

}
