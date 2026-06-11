#include <fstream>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, M;

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    if (N&1) {
        N -= N&1;
        F0R(i,M) cout << i+1 << ' ' << N-i << '\n';
    } else {
        F0R(i,M) {
            if (N-2*i-1 <= N/2) cout << i+1 << ' ' << N-i-1 << '\n';
            else cout << i+1 << ' ' << N-i << '\n';
        }
    }
}