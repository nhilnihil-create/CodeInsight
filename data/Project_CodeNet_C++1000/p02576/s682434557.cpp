#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int a = n / x;
    if (n%x == 0) cout << a*t << endl;
    else cout << a*t + t << endl;
    return 0;
}