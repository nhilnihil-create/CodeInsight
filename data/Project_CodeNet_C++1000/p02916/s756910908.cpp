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

    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N-1);

    REP(i,N){ cin >> A[i]; }
    REP(i,N){ cin >> B[i]; }
    REP(i,N-1){ cin >> C[i]; }

    ll total = 0;
    REP(j, N){
        int i = A[j]-1;
        total += B[i];
        if( j > 0 && (A[j-1]+1) == A[j] ){
            total += C[A[j-1]-1];
        }
    }
    cout << total << endl;
}
