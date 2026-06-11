#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
int mod=1e9+7;
const int N=2e5+100;

int num[N],cnt[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int l=max(1,j-num[j]);
            int r=min(n+1,j+num[j]+1);
            cnt[l]++,cnt[r]--;
        }
        bool f=true;
        for(int i=1;i<=n;i++){
            num[i]=num[i-1]+cnt[i];
            cnt[i]=0;
            if(num[n]==n) f=false;
        }
        if(!f) break;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",num[i]);
    return 0;
}

