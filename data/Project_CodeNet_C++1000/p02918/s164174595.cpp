#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<int> LR;
    int cnt = 1;
    repd(i, 1, S.size()) {
        if (S[i] != S[i - 1]) {
            LR.push_back(cnt);
            cnt = 0;
        }
        cnt++;
    }

    LR.push_back(cnt);

    int index = K * 2 - 1;
    int ans = 0;

    int lenLR = LR.size();
    for (int i = 0; i <= index + 1; i++) {
        if (i >= lenLR) break;
        ans += LR[i];
    }

    for (int i = index + 2; i < lenLR; i++) {
        ans += LR[i] - 1;
    }

    cout << ans - 1 << endl;
    return 0;
}