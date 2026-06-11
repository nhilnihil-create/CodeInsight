#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+9;
int A[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&A[i]);
    while(k--)
    {
        int B[maxn];
        memset(B,0,sizeof(B));
        for(int i=1;i<=n;i++)
        {
            int l = max(1,i-A[i]);
            int r = min(n,i+A[i]);
            //差分
            B[l]++;
            B[r+1]--;
        }
        //差分应用
        int flag = 1;
        for(int i=1;i<=n;i++)
        {
            A[i] = A[i-1] + B[i];
            if(A[i]!=n) flag = 0;
        }
        //剪枝
        if(flag) break;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
