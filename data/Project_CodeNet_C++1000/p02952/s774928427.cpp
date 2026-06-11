#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int ketasuu(int n){
    int ans = 1;
    int a = n;
    while(a > 9){
        ans++;
        a /= 10;
    }
    return ans;
}

int main() {
    int n, ans;
    cin >> n;
    int d = ketasuu(n);
    if(d==6){
        ans = 9 + 900 + 99999 - 10000 + 1;
    } else if(d==5){
        ans = 9 + 900 + n - 10000 + 1;
    } else if(d == 4){
        ans = 9 + 900;
    } else if(d == 3){
        ans = 9 + n - 100 + 1;
    } else if(d == 2){
        ans = 9;
    } else {
        ans = n - 1 + 1;
    }
    cout << ans << endl;
    return 0;
}
