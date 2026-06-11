#include <bits/stdc++.h>
using namespace std;

int A[3][3];

int is_bingo(){
    int i,j;
    for(i=0;i<3;i++){
        if(A[i][i]!=0)break;
        if(i==2)return 1;
    }
    for(i=0;i<3;i++){
        if(A[i][2-i]!=0)break;
        if(i==2)return 1;
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(A[i][j]!=0)break;
            if(j==2)return 1;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(A[j][i]!=0)break;
            if(j==2)return 1;
        }
    }
    return 0;
}

void mark(int B[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(A[j][k]==B[i])A[j][k]=0;
            }
        }
    }
    return;
}

int main(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)scanf("%d",&A[i][j]);
    }
    int n;
    cin>>n;
    int B[n];
    for(i=0;i<n;i++)scanf("%d",&B[i]);
    mark(B,n);
    if(is_bingo())printf("Yes\n");
    else{printf("No\n");}
}