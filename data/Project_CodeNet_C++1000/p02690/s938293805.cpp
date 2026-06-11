#include <bits/stdc++.h>
using namespace std;

#define ipr pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rf(i, j, k) for (int i = j; i >= k; i--)
#define ll unsigned long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp make_pair
#define cnt_ones(x) __builtin_popcountll(x)

#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const int Maxn = (int)1e6;
const ld pi = acos(-1);
const int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 1, (int)A.size()) out << A[i] + 1 << " ";
    return out;
}

template <class T1, class T2>
T1 powr(T1 a, T2 b) {
    T1 res = 1;
    fr(i, 1, b + 1) res = res * a;
    return res;
}

int32_t main() {
    IOS int n;
    cin >> n ;  bool flag = false;
    fr(i,-3000,3001)    fr(j,-3000,3001){
        if((powr(i,5) - powr(j,5)) == n){
            cout << i << " " << j << endl;
            flag = true;
            break;
        }
        if(flag)    break;
    }
    return 0;
}
