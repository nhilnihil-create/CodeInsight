#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const int mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 11


int main()
{
    int l,r,d; cin >> l >> r >> d;
    int cnt = 0;
    for(int i = l ; i <= r; i++){
        if(i % d == 0) cnt++;
    }
    cout << cnt << endl;
}