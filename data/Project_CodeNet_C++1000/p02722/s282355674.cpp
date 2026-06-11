#include <fstream>
#include <vector>
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

lli N;
vector<lli> nfact;
vector<lli> nfact1;

void fact(lli n, vector<lli>& store) {
    for (lli i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            store.PB(i);
            if (i*i != n) store.PB(n/i);
        }
    }
}

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    fact(N, nfact);
    fact(N-1, nfact1);

    int ans = nfact1.size() - 1;
    // cout << "pre: " << ans << '\n';
    for (lli cand: nfact) {
        if (cand == 1) continue;
        lli h = N;
        while (!(h%cand)) h /= cand;
        if (h%cand == 1) ans++;
    }
    cout << ans << '\n';
}