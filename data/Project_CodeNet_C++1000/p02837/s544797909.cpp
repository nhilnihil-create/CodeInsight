#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int fie[20][20];
int main(){
    int N;
    cin>>N;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++)fie[i][j]=10;
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        int A;
        cin>>A;
        for(int j=0;j<A;j++){
            int x,y;
            cin>>x>>y;
            fie[i][x]=y;

        }
    }
    for(int i=0;i<(1<<N);i++){
        int flg=1;
        int karians=0;
        for(int j=1;j<=N;j++){
            if(i&(1<<(j-1))){
                karians++;
                for(int k=0;k<20;k++){
                    if(fie[j][k]!=10){
                        //printf("[%d][%d][%d][%d][%d]\n",i,j,k,fie[j][k],(int)(i&(1<<(k-1))));
                        if((fie[j][k]==0)&&((int)(i&(1<<(k-1))))!=0)flg=0;
                        if((fie[j][k]!=0)&&((int)(i&(1<<(k-1))))==0){
                                //puts("hoge");
                                flg=0;
                        }
                    }
                }
            }
        }

        if(flg){
            //printf("===========[%d][%d]\n",i,karians);
            ans=max(ans,karians);
        }
    }
    cout<<ans<<endl;
    return 0;
}
