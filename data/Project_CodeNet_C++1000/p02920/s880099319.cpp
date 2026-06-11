#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    int N;
    cin >> N;

    int M = 1 << N;

    vector<int> S(M);
    rep(i, M) cin >> S[i];

    sort(S.begin(), S.end());
    
    vector<bool> used(M, false);
    vector<int> V;
    V.push_back(S[M - 1]);
    used[M - 1] = true;

    rep(i, N) {
        int n = V.size();
        rep(j, n) {
            int index = lower_bound(S.begin(), S.end(), V[j]) - S.begin();
            if (!index) {
                puts("No");
                return 0;
            }
            index--;

            V.push_back(S[index]);
            used[index] = true;

            S.erase(S.begin() + index);
        }
    }

    puts("Yes");
}