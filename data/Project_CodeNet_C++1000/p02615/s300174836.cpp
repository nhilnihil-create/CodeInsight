# include <iostream>
# include <cstdio>
# include <algorithm>
# include <queue>
# include <cstring>
# include <stack>
using namespace std;

priority_queue<long long> q;
long long A[300000];
int main(void)
{
    // freopen("aaa.in","r",stdin);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&A[i]);
    }
    long long ans = 0;
    sort(A+1,A+n+1);
    q.push(A[n]);
    for (int i=n-1;i>=1;i--)
    {
        int x = q.top();
        ans+=x;
        // cout<<x<<endl;
        q.pop();
        q.push(A[i]);
        q.push(A[i]);
    }
    printf("%lld\n",ans);

    return 0;
}