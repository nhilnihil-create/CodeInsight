#include <fstream>
#include <algorithm>
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

lli N, M, V, P;
lli arr [100000];
lli psum [100000];

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> V >> P;
    F0R(i,N) cin >> arr[i];
    sort(arr,arr+N);
    reverse(arr,arr+N);
    FOR(i,P-1,N) {
        psum[i] = arr[i];
        if (i != 0) psum[i] += psum[i-1];
    }

    int ans = 0;
    F0R(i,N) {
        if (i < P) {ans++; continue;}
        if (arr[i]+M < arr[P-1]) break;
        // cout << (arr[i]+M)*(i-P+1) - psum[i-1] << " **\n";
        if ((arr[i]+M)*(i-P+1) - psum[i-1] >= max(0ll, V-(N-i + P-1))*M) {
            ans++;
        }
    }
    cout << ans << '\n';
}