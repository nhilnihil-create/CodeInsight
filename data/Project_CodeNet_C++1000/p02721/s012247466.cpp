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

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, K, C;
string S;
int earl [200000];
int late [200000];

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> C >> S;
    int ind = 0;
    F0R(i,K) {
        while (S[ind] == 'x' && ind != N-1) ind++;
        earl[i] = ind;
        ind += C+1;
    }
    ind = N-1;
    RF0(i,K) {
        while (S[ind] == 'x' && ind != 0) ind--;
        late[i] = ind;
        ind -= C+1;
    }
    F0R(i,K) {
        if (earl[i] == late[i]) cout << earl[i]+1 << '\n';
    }
}