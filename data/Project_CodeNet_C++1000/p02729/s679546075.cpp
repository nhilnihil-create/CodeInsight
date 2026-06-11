#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

/*--- 異なるn個からr個の整数を取り出す組み合わせの数を返す ---*/
int combination(int n, int r)
{
    if(n<r) return (0);
    else if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

int main(void) {
    int N,M; cin >> N >> M;
    int ans = combination(N,2) + combination(M,2);
    cout << ans << endl;
}