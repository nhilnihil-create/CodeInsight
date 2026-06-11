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
const int M = 1e5 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,a[N],b[N];
vector<int> d[N];
deque<int> ans;
bool flag;

void seive() {

    for(int i = 1; i < N; ++i) {

        for (int j = i; j < N; j+=i) {

            d[j].pb(i);

        }

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    seive();

    for (int i = n; i >= 1; --i) {

        if(b[i]!=a[i]) {

            for(auto divisor: d[i]) {

                b[divisor] ^= 1;

            }

            ans.push_front(i);

        }

    }

    if(flag) {
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << '\n';

    for(auto i:ans) cout << i << ' ';

    return 0;
}