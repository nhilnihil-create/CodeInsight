#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define eb emplace_back
#define mp make_pair
using namespace std;
const int MAX_N=510;
int a[MAX_N][MAX_N],n;
void solve(int l,int r,int level){
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    for(int i=l;i<=mid;i++){
        for(int j=mid+1;j<=r;j++){
            a[i][j]=level;
        }
    }
    solve(l,mid,level+1);
    solve(mid+1,r,level+1);
}
int main(){
    scanf("%d",&n);
    solve(1,n,1);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}