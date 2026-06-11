#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define fi first
#define se second
#define debug printf(" I am here\n");
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1000+5,inf=0x3f3f3f3f;
const double eps=1e-10;
int n;
signed main(){
    scanf("%d",&n);
    int ma1=-inf,mi1=inf,ma2=-inf,mi2=inf;
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        ma1=max(ma1,x-y);
        mi1=min(mi1,x-y);
        ma2=max(ma2,x+y);
        mi2=min(mi2,x+y);
    }
    printf("%d\n",max(ma1-mi1,ma2-mi2));
    return 0;
}


