#include<bits/stdc++.h>

using namespace std;

int n,m,x;
int book[15][15];

int rekurzija(int i,int zbr[],int cost){
    bool t=true;
    for(int j=0;j<m;j++)
        if(zbr[j]<x)
            t=false;
    if(t)
        return cost;
    if(i>n)
        return INT_MAX;
    int new_zbr[m];
    for(int j=0;j<m;j++)
        new_zbr[j]=zbr[j]+book[i][j+1];
    return min(rekurzija(i+1,zbr,cost),rekurzija(i+1,new_zbr,cost+book[i][0]));
}

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)
        for(int j=0;j<=m;j++)
            cin>>book[i][j];
    int zbr[m];
    memset(zbr,0,sizeof(zbr));
    int rj=rekurzija(0,zbr,0);
    if(rj==INT_MAX)
        cout << -1<<endl;
    else
        cout <<rj<<endl;
}
