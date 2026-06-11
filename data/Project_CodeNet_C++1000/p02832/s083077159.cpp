#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(S, s) S.find(s) != string::npos

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    bool flag = false;
    Rep(i, N) {
        cin >> a[i];
        if (a[i] == 1) flag = true;
    }
    if (!flag) cout << -1 << endl;
    else {
        int index = 1, ans = 0;
        Rep(i, a.size()) {
            if (a[i] != index) {
                ans++;
            }
            else {
                index++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}