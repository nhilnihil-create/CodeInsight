#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int d, t, s;
    cin >> d >> t >> s;
    if (d <= t*s) puts("Yes");
    else puts("No");
    return 0;
}