#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    vector<int> sum(n);
    rep(i, n) {
        cin >> s[i] >> t[i];
        if ( i == 0 ) sum[0] = t[i];
        else          sum[i] = sum[i-1] + t[i];
    }
    string x;
    cin >> x;
    int num = 0;
    rep(i, n) {
        if ( s[i] == x ) num = i;
    }
    cout << sum[n-1] - sum[num] << endl;
    return 0;
}
