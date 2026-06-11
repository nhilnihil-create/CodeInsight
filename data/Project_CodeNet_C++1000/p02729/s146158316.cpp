#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    int n, m, ans = 0;
    cin >> n >> m;

    ans += ((n)*(n-1))/2;
    ans += (m*(m-1))/2;

    cout << ans << endl;
    return 0;
}