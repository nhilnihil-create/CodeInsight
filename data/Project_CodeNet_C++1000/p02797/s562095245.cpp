#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n, k, s;
    cin >> n >> k >> s;
    if(s<(ll)pow(10,9)){
        rep(i, k) cout << s << " ";
        rep(i, n - k) cout << s + 1 << " ";
        cout << endl;
    }else{
        rep(i,k)cout<<s<<" ";
        rep(i, n - k) cout << 1 << " ";
        cout << endl;
    }
}