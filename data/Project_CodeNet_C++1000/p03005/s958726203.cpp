#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    if(k == 1) cout << 0 << endl;
    else cout << n - k << endl;
    return 0;
}