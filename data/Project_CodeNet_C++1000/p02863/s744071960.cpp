#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool com(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    else{
        return a.second>b.second;
    }
}
int fie[2][3100][3100];
int main(){
    int N,T;
    cin>>N>>T;
    pair<int,int> AB[3000];
    for(int i=0;i<N;i++)cin>>AB[i].first>>AB[i].second;
    sort(AB,AB+N,com);
    //for(int i=0;i<N;i++)printf("[%d][%d]\n",AB[i].first,AB[i].second);
    for(int i=0;i<2;i++){
        for(int j=0;j<3100;j++){
            for(int k=0;k<3100;k++){
                fie[i][j][k]=-1;
            }
        }
    }
    fie[0][0][0]=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<3100;k++){
                if(fie[i][j][k]!=-1){
                    if(i==0){
                        fie[0][j+1][k]=max(fie[i][j][k],fie[0][j+1][k]);
                        fie[1][j+1][k]=max(fie[i][j][k]+AB[j].second,fie[1][j+1][k]);
                        //fie[1][j+1][k+AB[j].first]
                    }
                    else{
                        fie[1][j+1][k]=max(fie[i][j][k],fie[1][j+1][k]);
                        if(k+AB[j].first<3100){
                            fie[1][j+1][k+AB[j].first]=max(fie[i][j][k]+AB[j].second,fie[1][j+1][k+AB[j].first]);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<2;i++){
        for(int k=0;k<T;k++){
            ans=max(ans,fie[i][N][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

