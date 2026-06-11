#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    string S;
    int Q;
    cin >> S >> Q;
    bool flag = 0;
    const int rev = 3;
    Rep(i, Q) {
        int T;
        cin >> T;
        if (T == 1) flag = 1 - flag;
        else {
            int F;
            char C;
            cin >> F >> C;
            if (flag) F = rev - F;
            if (F == 1) S = C + S;
            else S += C;
        }
    }
    if (flag) Reverse(S);
    cout << S << endl;
    return 0;
}