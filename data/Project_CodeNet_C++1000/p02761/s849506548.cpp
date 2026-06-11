#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,si,ci,ans;ans=0;
    scanf("%d%d",&n,&m);
    unordered_map<int,int> mp;
    int num[n+1];
    for(int i=1;i<=n;i++)num[i]=10;
    if (m==0&&n==1){
        printf("0\n");
        return 0;
    }
    for(int i=0;i<m;i++){
        cin >> si >> ci;
        if(mp.find(si)!=mp.end()&&mp[si]!=ci)ans=-1;
        mp[si]=ci;
        if(si==1&&ci==0&&n>=2) ans=-1;
        num[si] = ci;
    }
    if (ans==-1) {
        printf("%d\n", ans);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(num[i]==10){
            if(i==1)num[i]=1;
            else num[i]=0;
        }
        ans+=num[i]*pow(10,n-i);
    }
    printf("%d\n",ans);
}