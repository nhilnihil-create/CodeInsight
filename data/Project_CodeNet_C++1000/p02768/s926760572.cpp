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

const int Maxn = (int)1e5 + 1;
const ld pi = acos(-1);
const int mod = (int)1e9 + 7;
const int inf = (int)1e18;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    fr(i, 0, (int)A.size()) out << A[i] << " ";
    return out;
}


int fastmod(int e, int x) {
    int res = 1;
    e %= mod;
    if (e == 0) return 0;
    while (x > 0) {
        if (x & 1) res = (res * e) % mod;
        x >>= 1;
        e = (e * e) % mod;
    }
    return res;
}

int modulo_inverse(int a) { return fastmod(a, mod - 2); }

int cal_factorial(int n) {
    int ans = 1;
    fr(i,2,n+1){
        ans = ans*i;
        ans %= mod;
    }
    return ans;
}

int binent(int n, int r) {
    int ans = 1;
    fr(i,n-r+1,n+1){
        ans = (ans*i)%mod;
    }
    //cout << ans << " guess " << endl;
    return ans;
}

int32_t main() {
    IOS     int n,a,b;  cin>>n>>a>>b;
    int temp1 = fastmod(2,n)-1;
    //cout << binent(5,2) << " ok " << endl;
    int temp2 = ((binent(n,a)*modulo_inverse(cal_factorial(a))) % mod + 
                (binent(n,b)*modulo_inverse(cal_factorial(b)))%mod)%mod;
                //cout << temp2 << " ok " << endl;
    int ans = (temp1-temp2 + mod)%mod;
    cout << ans << endl;
    return 0;
}
