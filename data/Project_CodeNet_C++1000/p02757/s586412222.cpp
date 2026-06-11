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
#define ll long long
#define pii pair<int,int>
#define add(a,b,m) ((int) (((ll) (a) + (b))%(m)))
#define mul(a,b,m) ((int) (((ll) (a) * (b))%(m)))
#define PB emplace_back

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

int N, P;
ll ans = 0;
string S;
int ct [10001] = {0};

// Helper Functions

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P >> S;
    if (P == 2 || P == 5) {
        ll cur = 0;
        RF0(i,N) {
            cur += ((S[i]-'0')%P == 0);
            ans += cur;
        }
        cout << ans << '\n';
        return 0;
    }
    ct[0]++;
    int md = 0;
    int pw = 1;
    RF0(i,N) {
        md = add(md, mul(S[i]-'0',pw,P),P);
        ans += ct[md];
        ct[md]++;
        pw = mul(pw, 10,P);
    }
    cout << ans << '\n';
}