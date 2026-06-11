#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;


int main(){
    ll h, w;
    cin >> h >> w;
    ll ans;
    ans = (h * w) + 1;
    ans /= 2;
    if(h == 1 || w == 1) ans = 1;
    cout << ans << endl;
    return 0;
}
