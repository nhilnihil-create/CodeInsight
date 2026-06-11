//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ll n, m, v, p;
    cin >> n >> m >> v >> p;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    if(v <= p) {
        sort(all(a));
        int cri = a[n-p];
        int x = a.end()-lower_bound(all(a), cri-m);
        cout << x << endl;
    } else {
        sort(all(a));
        int cri = a[n-p];
        auto itr = lower_bound(a.begin()+v-p, a.end(), cri-m);
        int x = a.end()-itr;
        if(itr == a.begin()+v-p) {
            ll sum = 0;
            int ww = 0;
            for(auto iitr = a.end()-p; iitr >= itr; --iitr) {
                sum += cri-*iitr;
                ww++;
            }
            int j = v-p-1;
            int cou = 1;
            while(j >= 0) {
                ll ff = cou*m-sum;
                if(ff < 0) ff = 0;
                if(m+a[j] >= cri+(ff+ww-1)/ww) {
                    x++;
                } else {
                    break;
                }
                cou++;
                ww++;
                sum += cri-a[j];
                --j;
            }

        }
        cout << x << endl;

    }
}