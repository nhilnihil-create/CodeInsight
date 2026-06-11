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

int N, a;
lli arr [100001];
lli psum [100001] = {0};

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    F0R(i,N+1) cin >> arr[i];
    RF0(i,N) psum[i] = arr[i+1] + psum[i+1];
    
    lli t_nodes = 0;
    lli lvl = 1;
    F0R(i,N+1) {
        if (lvl-arr[i] < 0 || lvl-arr[i] > psum[i]) {cout << "-1\n"; return 0;}
        t_nodes += lvl;
        lvl = min(2*(lvl-arr[i]), psum[i]);
    }
    cout << t_nodes << '\n';
}