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

const int N = 3e5 + 5;
const int M = 5e5 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int t,n,a[N],freq[N],cum[N];

void init() {



}

bool f(int m, int k) {
    if(m==n) return 0;
    return cum[m]/(m-n+k) >= freq[m+1];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    sort(freq+1, freq+1+n);

    for (int i = 1; i <= n; ++i) {
        cum[i] = cum[i-1] + freq[i];
    }

    for (int k = 1; k <= n; ++k) {

        int s = n-k+1, e = n;

        while (s<e) {

            int m = (s+e)/2;

            if(f(m, k)) {
                s = m + 1;
            } else {
                e = m;
            }

        }

        cout << cum[e]/(e-(n-k)) << '\n';

    }

    return 0;
}