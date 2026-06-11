#include<bits/stdc++.h>
using namespace std;
int coin[]={500,100,50,10,5,1};
int main(){
    int N;
    while(scanf("%d",&N),N){
        N=1000-N;
        int ans=0;
        for(int i=0;i<6;i++){
            ans+=N/coin[i];
            N%=coin[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}