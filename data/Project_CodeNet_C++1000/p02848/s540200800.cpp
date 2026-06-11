#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    string S;
    cin >> N >> S;

    rep(i, S.length()) S[i] = char((int(S[i]) - int('A') + N) % 26 + int('A'));

    cout << S << endl;

    return 0;
}