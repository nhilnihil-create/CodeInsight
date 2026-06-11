#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
int a[3][3],n;
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
int main() {
 // 入力
    int N, A;
    cin >> N >> A;

    // 処理
    int L = A;
    int R = A + N - 1;

    int eat;
    if (R <= 0)
        eat = R;
    else if (L >= 0)
        eat = L;
    else
        eat = 0;

    int answer = (R + L) * (R - L + 1) / 2 - eat;

    // 出力
    cout << answer << endl;

    return 0;

}
