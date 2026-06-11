#include "bits/stdc++.h"
using namespace std;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    Rep(i, N) {
        string s;
        cin >> s;
        Sort(s);
        S[i] = s;
    }
    Sort(S);
    ll cnt = 0, ans = 0;
    string now = "";
    Rep(i, N) {
        if (now == "") {
            now = S[i];
            cnt++;
            continue;
        }
        if (S[i] == now) {
            cnt++;
        }
        else {
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            now = S[i];
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
    return 0;
}
