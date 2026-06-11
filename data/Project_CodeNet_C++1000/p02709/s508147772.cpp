#include <iostream>
#include<cstdio>
#include <algorithm>
#include<string>
#include<queue>
using namespace std;
const int N=2020;
long long ans[N][N],sum;
int n;
struct node{
    int val,id;
}a[N];
bool cmp(node x,node y){
    return x.val>y.val;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].val),a[i].id=i;
    sort(a+1,a+n+1,cmp);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i+j>=n)continue;
            int num=i+j+1;
            ans[i][j+1]=max(ans[i][j+1],1ll*(n-j-a[num].id)*a[num].val+ans[i][j]);
            ans[i+1][j]=max(ans[i+1][j],1ll*(a[num].id-1-i)*a[num].val+ans[i][j]);
        }
    }
    for(int i=0;i<=n;i++)
        if(ans[i][n-i]>sum)sum=ans[i][n-i];
    cout<<sum<<endl;
}