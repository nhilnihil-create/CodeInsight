// Recall: Iterating all subsets --> Iterate sub-subsets --> Total count = 3^N
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define REP(i,n)   FOR(i,0,n)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back

const LL MOD = 998244353LL;
const int MAX_N = 3333;
int N, S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    vector<int> A(N + 1);
    FOE(i, 1, N) cin >> A[i];

    std::vector<LL> Old(S + 1);
    FOE(i, 0, S) Old[i] = LL(i == 0);

    FOE(i, 1, N) {
        //cout << endl << "A) "; FOE(i, 0, S) cout << Old[i] << " "; cout << endl;

        std::vector<LL> Cur = Old;
        FOE(s, A[i], S) {
            Cur[s] += Old[s - A[i]];
            Cur[s] %= MOD;
        }
        //cout << "B) "; FOE(i, 0, S) cout << Old[i] << " "; cout << endl;
        //cout << "B) "; FOE(i, 0, S) cout << Cur[i] << " "; cout << endl;
        FOE(s, 0, S) {
            Cur[s] += Old[s];
            Cur[s] %= MOD;
        }
        //cout << "C) "; FOE(i, 0, S) cout << Cur[i] << " "; cout << endl;
        Old = std::move(Cur);
    }

    cout << Old[S] << endl;

    return 0;
}
