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
    int n;
    cin >> n;
    vector<int> buka(n, 0);
    // int buka[n];
    rep(i, n - 1){
        int tmp;
        cin >> tmp;
        tmp--;
        buka[tmp]++;
    }

    rep(i, n){
        cout << buka[i] << endl;
    }
    return 0;
}
