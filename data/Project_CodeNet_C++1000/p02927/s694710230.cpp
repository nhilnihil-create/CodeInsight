#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j%10>=2&&j/10>=2&&j%10*(j/10)==i)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}