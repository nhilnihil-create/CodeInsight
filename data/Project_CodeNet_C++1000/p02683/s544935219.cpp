#include <bits/stdc++.h>
using namespace std;
int n,m,x;
vector<vector<int> >v(12,vector<int>(13));
int mn=INT_MAX;

void slv(int msk=0,int lsti=0,int ttl=0){
    vector<int>v2(m);
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if((1<<i)&msk)
                v2[j]+=v[i][j+1];
        }
    }
    int f=1;
    for(int j=0;j<m;j++){
        if(v2[j]<x){
            f=0;
            break;
        }
    }
    if(f){
        mn=min(mn,ttl);
        return;
    }
    for(int i=lsti;i<n;i++){
        if((msk&(1<<i))==0){
            slv(msk|(1<<i),i,ttl+v[i][0]);
        }
    }
}

int main()
{
    cin>>n>>m>>x;
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        for(int j=1;j<m+1;j++)
            cin>>v[i][j];
    }
    slv();
    if(mn==INT_MAX)
    cout<<-1<<'\n';
    else
    cout<<mn<<'\n';
    return 0;

}
/***
3 3 10
60 2 2 4
70 8 7 9
50 2 3 9
3 3 10
100 3 1 4
100 1 5 9
100 2 6 5
*/
