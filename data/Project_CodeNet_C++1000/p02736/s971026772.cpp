#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1000005;
const int INF = 1001001001;
const int MOD = 1000000007;

vector<int> table;
void init(int N) {
    table.resize(N);
    for (int i = 1; i < N; ++i) {
        int x = i, res = 0;
        while (x > 0 && x % 2 == 0) {
            x /= 2;
            res++;
        }
        table[i] = table[i-1] + res;
    }
}

int f(vector<int>& V) {
    int N = V.size(), res = 0;
    rep(i, N) {
        if (table[N - 1] == table[i] + table[N - 1 - i]) {
            res += V[i];
        }
    }

    if (res % 2) return 1;
    if (count(V.begin(), V.end(), 1) > 0) return 0;
    for (int &i : V) i /= 2;
    if (count(V.begin(), V.end(), V[0]) == N) return 0;
    return 2 * f(V);
}

int main(){
    int N;
    string S;
    cin >> N >> S;

    vector<int> A(N);
    rep(i, N) A[i] = S[i] - '1';

    init(N);
    cout << f(A) << endl;
}