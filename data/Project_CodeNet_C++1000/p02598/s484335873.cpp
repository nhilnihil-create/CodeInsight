#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<n;i++)

int N, K;
int A[200010];

signed main()
{
    cin >> N >> K;
    rep(i, N)cin >> A[i];

    sort(A, A + N);

    if(K == 0)
    {
        cout << A[N - 1] << endl;
        return 0;
    }

    int l = 1, r = 1001001001001001001;
    rep(i, 70)
    {
        int mid = (l + r) / 2;
        int cnt = 0;
        rep(j, N)
            cnt += (A[j] + mid - 1) / mid - 1;
        if(cnt <= K)r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}
