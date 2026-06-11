#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        int imoss[60*60*24+100]={0};
        for(int i=0;i<n;i++){
            int t,m,s;
            scanf("%d:%d:%d",&t,&m,&s);
            imoss[t*3600+m*60+s]++;
            scanf("%d:%d:%d",&t,&m,&s);
            imoss[t*3600+m*60+s]--;
        }
        for(int i=1;i<=24*60*60;i++)imoss[i]+=imoss[i-1];
        int ma=0;
        for(int i=0;i<=24*60*60;i++)ma=max(ma,imoss[i]);
        printf("%d\n",ma);
    }
    return 0;
}