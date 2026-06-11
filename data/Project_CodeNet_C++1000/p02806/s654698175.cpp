#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int N;
vector<string> S;
vector<int> T;
string X;


void input() {
    cin >> N;
    S = vector<string>(N);
    T = vector<int>(N);
    rep(i, N) cin >> S[i] >> T[i];
    cin >> X;
}


int main() {
    input();
    vector<int> sum(N+1);
    sum[0] = 0;
    rep(i, N) sum[i+1] = sum[i] + T[i];
    int x = 0;
    while (S[x] != X) x++;
    int ans = sum.back() - sum[x+1];
    cout << ans << endl;
}
