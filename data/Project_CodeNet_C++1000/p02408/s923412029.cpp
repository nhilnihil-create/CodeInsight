#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * vector<int>ar(3);
 * for(auto&e:ar){
 *     scanf("%d",&e);
 * }
 * sort(ar.begin(),ar.end())
 * int sum=accumulate(ar.begin(),ar.end(),0);
 ***/

int main(){
    double pai=3.141592653589;
    int n,p;
    char s;
    int card[4][13];
    scanf("%d",&n);
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            card[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%s %d",&s,&p);
        if(s=='S'){
            card[0][p-1]=1;
        }else if(s=='H'){
            card[1][p-1]=1;
        }else if(s=='C'){
            card[2][p-1]=1;
        }else if(s=='D'){
            card[3][p-1]=1;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(card[i][j]==0){
                if(i==0) printf("S %d\n",j+1);
                if(i==1) printf("H %d\n",j+1);
                if(i==2) printf("C %d\n",j+1);
                if(i==3) printf("D %d\n",j+1);
            }
        }
    }
    return 0;
}