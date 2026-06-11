//https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_a
// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
// clang-format on
int main()
{
    int N, K;
    cin >> N >> K;
    cout << (K == 1 ? 0 : (N - K + 1) - 1) << endl;
    return 0;
}