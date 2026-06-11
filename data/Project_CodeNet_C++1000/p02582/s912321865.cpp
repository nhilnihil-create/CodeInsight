#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    if (S == "RRR") ans = 3;
    else if (S == "RRS" || S == "SRR") ans = 2;
    else if (S == "SSS") ans = 0;
    else ans = 1;
    cout << ans << endl;
    return 0;
}