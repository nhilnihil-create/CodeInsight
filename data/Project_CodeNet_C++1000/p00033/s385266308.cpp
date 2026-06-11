#include<cstdio>
#include<iostream>
int mitaball(int n,int Bn,int Cn);
int ball[10],B[10]={0},C[10]={0};
int judge;
int a;
int x;
int main(){
    scanf("%d",&x);
    for(int j=0;j<x;j++){
        judge=0;
        for(int i=0;i<10;i++)
            scanf("%d",&ball[i]);
        mitaball(0,0,0);
        if(judge==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
int mitaball(int n,int Bn,int Cn){
    /*
    if(judge==0){
        if(n==10){
                                for(int k=0;k<10;k++)
                    printf("[%d][%d]\n",B[k],C[k]);
            for(int i=0;i<Bn-1;i++){
                if(B[i]>B[i+1])
                    break;
                judge=1;
            }
            for(int i=0;i<Cn-1;i++){
                if(C[i]>C[i+1]||judge==0){
                    judge=0;
                    break;
                }
                judge=1;
            }
        }
        else{
    */      if(n==10)
                judge=1;
            if(judge==0)
                if(Bn==0||B[Bn-1]<ball[n]){
                    B[Bn]=ball[n];
                        mitaball(n+1,Bn+1,Cn);
                    B[Bn]=0;
                }
                if(Cn==0||C[Cn-1]<ball[n]){
                C[Cn]=ball[n];
                    mitaball(n+1,Bn,Cn+1);
                C[Cn]=0;
            }
    /*
        }
    }
    */
}