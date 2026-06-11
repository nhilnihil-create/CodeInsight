#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cstdlib>
#include<ctime>
#include<random>
#define ll long long
using namespace std;

int k,n,ans,a[200007];

int main(){
    scanf("%d%d",&k,&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    ans=k;
    for (int i=2;i<n;++i){
        ans=min(ans,k-(a[i+1]-a[i]));
        ans=min(ans,k-(a[i]-a[i-1]));
    }
    ans=min(ans,a[n]-a[1]);
    printf("%d\n",ans);
}