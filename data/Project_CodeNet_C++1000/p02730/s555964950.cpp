#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

bool isKai(string S){
    string T = S;
    reverse(S.begin(), S.end());
    return T == S;
}

int main() {
    string S;
    cin >> S;
    int N = S.size();

    bool isOk1 = isKai(S);

    string S2 = S.substr(0, (N - 1) / 2);
    bool isOk2 = isKai(S2);

    string S3 = S.substr((N + 3) / 2 - 1); // 0-index
    bool isOk3 = isKai(S3);

    string ans = isOk1 && isOk2 && isOk3 ? "Yes" : "No";
    
    cout << ans << endl;

    return 0;
}
