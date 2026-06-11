#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
vector <tuple<int,int,int>>relation;
int n;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            ans+=j;
    printf("%lld",ans);
    
}