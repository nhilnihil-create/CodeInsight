#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    ll m; cin >> m;
    ll d[m],c[m];
    ll dig = 0;
    ll sum = 0;
    rep(i,m){
        cin >> d[i] >> c[i];
        sum += d[i] * c[i];
        dig += c[i];
    }
    cout << dig - 1 + (sum-1)/9 << endl;
}