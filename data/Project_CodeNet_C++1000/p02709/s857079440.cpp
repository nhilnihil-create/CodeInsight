#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=2e3+5;
int d[maxm][maxm];
PI a[maxm];
int n;
bool cmp(PI a,PI b){
    return a.first>b.first;
}
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=0;i<n;i++){
        for(int j=0;i+j<n;j++){//枚举当前状态
            int k=i+j+1;
            d[i][j+1]=max(d[i][j+1],d[i][j]+abs(n-j-a[k].second)*a[k].first);
            d[i+1][j]=max(d[i+1][j],d[i][j]+abs(i+1-a[k].second)*a[k].first);
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=max(ans,d[i][n-i]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
考虑贪心,显然对于权值大的数,选择最左边和最右边贡献大的位置.
但是如果最左边和最右边贡献一样大,就不好判断了,
因为会影响接下来其他数的贡献,
所以这题应该用dp做,

令d[i][j]表示i个元素放在最左边,j个元素放在最右边的最大权值和.
枚举每个状态,向下一个状态转移即可.
*/
