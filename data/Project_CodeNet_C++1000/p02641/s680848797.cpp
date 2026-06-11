#include <bits/stdc++.h>
using namespace std;
# define LL long long

int main(){
    int p[201]={0};
    int x,n;
    scanf("%d%d",&x,&n);
    for (int i=0;i<n;i++){
        int y;
        scanf("%d",&y);
        p[y]=1;
    }
    int i=x,j=x,ans;
    while (1){
        if (p[i]==0){
            ans=i;
            break;
        }
        if (p[j]==0){
            ans=j;
            break;
        }
        else{
            i-=1;
            j+=1;
        }
    }
    printf("%d",ans);
}