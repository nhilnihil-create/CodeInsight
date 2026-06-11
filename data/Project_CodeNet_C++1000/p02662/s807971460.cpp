#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vi2;
typedef vector<vi2> vi3;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef vector<vll> vll2;
typedef vector<vll2> vll3;
typedef vector<bool> vb;

#define el '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define umap unordered_map
#define uset unordered_set
#define vec vector
#define loop(a) for (auto &x : a)
#define all(a) a.begin(), a.end()
#define mp make_pair

const int modulo = 998244353;

void adds(int &a, int b) {
    a+=b;
    if (a >= modulo) {
        a-=modulo;
    }
}

int mul(int a, int b) {
    return (ll)a * b % modulo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vi a(n);
    loop(a) {
        cin >> x;
    }

    // cnt[k,s]: number of k subset of {a[0]..a[i]} with sum equaling to s

    vi2 cnt(n,vi(3001));
    cnt[0][0]=2;
    cnt[0][a[0]]=1;
    rep(i,1,n) {
        rep(s1,0,3001) {
            cnt[i][s1] = mul(2,cnt[i-1][s1]);
            if (s1 >= a[i]) {
                adds(cnt[i][s1], cnt[i-1][s1-a[i]]);
            }
        }
    }
    cout << cnt[n-1][s] << el;

    // cnt[s1]: number of subset of {a[0]..a[i]} with sum eqauling to s. 
    /* vi cnt(3001), cnt1(3001); */
    /* int ans = 0; */
    /* rep(i,0,n) { */
    /*     rep(s1,1,3001) { */
    /*         if (cnt[s1]>0) { */
    /*             int s2 = s1 + a[i]; */
    /*             if (s2 <= 3000) { */
    /*                 adds(cnt1[s2], cnt[s1]); */
    /*             } */
    /*         } */
    /*     } */
    /*     adds(cnt1[a[i]], 1); */
    /*     rep(s1,1,3001) { */
    /*         adds(cnt[s1], cnt1[s1]); */
    /*     } */
    /*     adds(ans, cnt[s]); */
    /*     cnt1.assign(3001, 0); */
    /* } */

    /* cout << ans << el; */
}
