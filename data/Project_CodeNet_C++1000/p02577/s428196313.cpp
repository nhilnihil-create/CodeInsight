#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    string N;
    cin >> N;
    ll sum = 0;
    rep(i, N.size()) {
        int n = N[i] - '0';
        sum += n;
    }

    if (sum%9 == 0) puts("Yes");
    else puts("No");
    return 0;
}