#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N, M;
int K;
int A[200010], B[200010];

signed main()
{
    cin >> N >> M >> K;
    rep(i, N)cin >> A[i];
    rep(i, M)cin >> B[i];

    int costA = 0;
    int costB = 0;
    int ans = 0;
    int numB = M;
    rep(i, M)costB += B[i];

    rep(i, N + 1)
    {
        if(i != 0)costA += A[i - 1];
        while(numB != 0 && K < costA + costB)
        {
            costB -= B[numB - 1];
            numB--;
        }

        if(costA + costB <= K)ans = max(ans, i + numB);
    }

    cout << ans << endl;

    return 0;
}