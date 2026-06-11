#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> hw(m);
    rep(i, m) cin >> hw[i];
    
    int ans = n - accumulate(hw.begin(), hw.end(), 0);
    ans = ans <= -1 ? -1 : ans;

    cout << ans << endl;
    return 0;
}
