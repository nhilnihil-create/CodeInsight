//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 2e5 + 5;
const int M = 1560 + 5;
const ll OO = 2e18;
const int mod = 1e9 + 7;

int n,p,pre[N];
string s;
ll ans;
map<int, int> m;

int mul(int a, int b) {

    return (a*b)%p;

}

int pw(int b, int k) {

    if(!k) return 1;

    int res = pw(b, k>>1);

    return mul(mul(res, res), (k&1 ? b : 1));

}

int modInv(int a) {

    return pw(a, p-2);

}

void init() {
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> p >> s;

    if(p==2 || p==5) {

        for (int i = 0; i < n; ++i) {
            if((s[i]-'0')%p==0) {
                ans += i+1;
            }
        }

    } else {

        for (int i = 0; i < n; ++i) {
            pre[i] = ((i ? pre[i-1] : 0) * 10 + (s[i] - '0'))%p;
        }

        m[0] = 1;

        for (int i = 0; i < n; ++i) {
            ans += m[mul(pre[i],modInv(pw(10,i)))]++;
        }

    }

    cout << ans << '\n';

    return 0;
}