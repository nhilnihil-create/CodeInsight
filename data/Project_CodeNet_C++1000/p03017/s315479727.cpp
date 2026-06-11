#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    A--, B--, C--, D--;

    bool res = false;
    if (C > D) {
        for (int i = B - 1; i < D; ++i) {
            if (i+2 < N && S[i] == '.' && S[i+1] == '.' && S[i+2] == '.') {
                res = true;
            }
        }
    } else {
        res = true;
    }

    while (B < D) {
        if (B+1 <= D && S[B+1] == '.') B++;
        else if (B+2 <= D && S[B+2] == '.') B += 2;
        else {
            res = false;
            break;
        }
    }

    while (A < C) {
        if (A+1 <= C && S[A+1] == '.') A++;
        else if (A+2 <= C && S[A+2] == '.') A += 2;
        else {
            res = false;
            break;
        }
    }

    cout << (res ? "Yes" : "No") << endl;
}