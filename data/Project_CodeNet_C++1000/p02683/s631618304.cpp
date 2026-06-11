#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N,M,X;
int mins=100100100;
vector<int> money;
vector<int> skillUpBpook;

int sum(vector<bool> bl,vector<vector<int>> skillUp){
    vector<int> readed(M+1,0);
    for(int a=0;a<N;a++){
        if(bl[a]==true){
            readed[0]+=money[a];
            for(int k=0;k<M;k++){
                readed[k+1]+=skillUp[a][k];
            }
        }
    }
    //for(int k=0;k<=M;k++)cout << readed[k]<<" ";
    //cout <<endl;
    for(int k=1;k<=M;k++){
        //cout << readed[k]<<" ";
        if(readed[k]<X){
            return 1001001000;
        }
        //cout <<endl;
    }
    //cout << "return";
    return readed[0];
}

void Dfs(vector<bool> df,vector<vector<int>> skillUp){
    if(df.size()==N){
        //cout <<df[0]<<df[1]<<df[2]<<endl;
        int cc=sum(df,skillUp);
        if(cc<mins){
            mins=cc;
        }
        return;
    }else if(df.size()<N){
        df.push_back(false);
        Dfs(df,skillUp);
        df.pop_back();
        df.push_back(true);
        Dfs(df,skillUp);
    }
}

int main(void)
{
    cin >> N>>M>>X;
    money.resize(N);
    skillUpBpook.resize(M);
    vector<vector<int>> skillUp(N,skillUpBpook);
    for(int a=0;a<N;a++){
        cin >> money[a];
        for(int b=0;b<M;b++){
            cin >> skillUp[a][b];
        }
    }
    vector<bool> df;
    Dfs(df,skillUp);
    if(mins==100100100){
        cout <<"-1"<<endl;
        return 0;
    }
    cout <<mins<<endl;
}