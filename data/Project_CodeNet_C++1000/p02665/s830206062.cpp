#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << endl;}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e17;
const ll mod = 1e9 + 7;

typedef tuple<long long, int, int> ti;

ll n;

ll bit[100005];

ll query(ll i) {
  ll ret = 0;
  for (; i>0; i-=i&-i)
    ret = min(inf, bit[i] + ret);
  return ret;
}

void update(ll i, ll val) {
  for (; i<=n; i+=i&-i)
    bit[i] = min(inf, bit[i] + val);
}

void supdate(ll i, ll val) {
    update(i, val);
    update(i + 1, -val);
}

//inclusive
void rupdate(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    n++;

    ll arr[n];

    f0r(i, n) cin >> arr[i];

    if (arr[0] > 1) {
        cout << -1 << endl;
        return 0;
    }

    if (arr[0] == 1) {
        if (n != 1)
            cout << -1 << endl;
        else {
            cout << 1 << endl;
        }
        return 0;
    }

    ll ret = 1;
    ll cur_ind = 1;
    bool pos = true;

    supdate(1, 2);


    for (int i = 1; i < n; i++) {
        /*for (int j = 1; j <= n; j++) {
            cout << query(j) << " ";
        }*/


        while (arr[i] > 0) {
            ll q = query(cur_ind);

            if (cur_ind > i) {
                pos = false;
                break;
            }

            if (q >= arr[i]) {
                ret += (i + 1 - cur_ind) * arr[i];
                supdate(cur_ind, -arr[i]);
                rupdate(cur_ind + 1, i, arr[i]);

                arr[i] = 0;
            } else {
                ret += (i + 1 - cur_ind) * q;
                supdate(cur_ind, -q);
                rupdate(cur_ind + 1, i, q);

                arr[i] -= q;

                cur_ind++;
            }
        }

        if (!pos) break;
    }

    if (!pos) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }








}
