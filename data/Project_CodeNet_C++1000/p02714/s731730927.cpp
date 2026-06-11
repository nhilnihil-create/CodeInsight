#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//int fie[4003][8][8003];
int main(){

    int N;
    string S;
    cin>>N>>S;
    long long int cou[3]={0,0,0};
    for(int i=0;i<N;i++){
        if(S[i]=='R')cou[0]++;
        if(S[i]=='G')cou[1]++;
        if(S[i]=='B')cou[2]++;
    }
    long long int ans=cou[0]*cou[1]*cou[2];
    //cout<<ans<<endl;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            //if(S[i]==S[j])continue;
            if(j+(j-i)<N){
                if(S[j+(j-i)]!=S[i]&&S[j+(j-i)]!=S[j]&&S[i]!=S[j]){
                    ans--;
                }
            }
        }
    }
    /*
    fie[0][0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8003;k++){
                if(j==0){
                    fie[i+1][0][0]+=fie[i][j][k];
                    if(S[i]=='R'){
                        fie[i+1][4][i]+=fie[i][j][k];
                    }
                    if(S[i]=='G'){
                        fie[i+1][2][i]+=fie[i][j][k];
                    }
                    if(S[i]=='B'){
                        fie[i+1][1][i]+=fie[i][j][k];
                    }
                }
                if(j==1||j==2||j==4){
                    fie[i+1][j][k]+=fie[i][j][k];
                    int bi;
                    if(S[i]=='R')bi=4;
                    if(S[i]=='G')bi=2;
                    if(S[i]=='B')bi=1;
                    if((bi&j)==0){
                        fie[i+1][bi|j][i+(i-k)]+=fie[i][j][k];
                    }
                }
                if(j==3||j==5||j==6){
                    fie[i+1][j][k]+=fie[i][j][k];
                    int bi;
                    if(S[i]=='R')bi=4;
                    if(S[i]=='G')bi=2;
                    if(S[i]=='B')bi=1;

                    if((bi&j)==0&&(i!=k)){
                        fie[i+1][bi|j][0]+=fie[i][j][k];
                    }

                }
                if(j==7){
                    fie[i+1][j][k]+=fie[i][j][k];
                }
            }
        }
    }

    long long int ans=0;
    for(int i=0;i<8003;i++){
        ans+=fie[N][7][i];
    }
    */
    cout<<ans<<endl;

    return 0;
}
