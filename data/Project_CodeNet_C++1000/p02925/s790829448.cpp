#include<bits/stdc++.h>
using namespace std;

const int sz=1100;
bool mark[sz];

int idx[sz];

int main()
{
    int n,m,p,q,x,y,i,j,k,a,b;

    cin>>n;
    int ara[n+1][n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<n;j++) cin>>ara[i][j];
        idx[i]=1;
    }

    int day=1;
    while(1)
    {
        memset(mark,false,sizeof mark);
        bool bl=false;

        for(i=1;i<=n;i++){
            if(mark[i] || idx[i]>=n) continue;
            p=ara[i][idx[i]];
            if(ara[p][idx[p]]==i && mark[p]==false){
                mark[i]=true, mark[p]=true, bl=true;
                ++idx[i], ++idx[p];
            }
        }

        if(!bl) break;
        ++day;
    }

    bool bl=true;

    for(i=1;i<=n;i++){
        if(idx[i]<n) {
            bl=false;
            break;
        }
    }

    if(!bl) cout<<"-1\n";
    else  cout<<day-1<<'\n';
}
