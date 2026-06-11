#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define pii pair<int,int>

int N;
int A[200010];
int mem[1000010];
int num[1000010];

signed main()
{
    cin >> N;
    rep(i, N)
    {
        cin >> A[i];
        num[A[i]]++;
    }

    sort(A, A + N);

    int ans = 0;
    rep(i, N)
    {
        if(mem[A[i]] == 0 && num[A[i]] == 1)ans++;
        if(mem[A[i]] == 0)for(int j = A[i]; j <= 1000000; j += A[i])mem[j] = 1;
    }

    cout << ans << endl;

    return 0;
}
