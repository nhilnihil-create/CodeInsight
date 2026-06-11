#include <bits/stdc++.h>

using namespace std;

long long INF=1e15;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        int n;
        cin>>n;

        if(n==0)break;

        int a[30][30]={};

        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            a[x][y]=1;
        }

        int m;
        cin>>m;

        int b[30][30]={};

        int pos_x=10,pos_y=10;

        for(int i=0;i<m;i++){
            char c;
            int d;
            cin>>c>>d;
            if(c=='N'){
                for(int j=pos_y;j<=pos_y+d;j++)b[pos_x][j]=1;
                pos_y+=d;
            }
            else if(c=='S'){
                for(int j=pos_y;j>=pos_y-d;j--)b[pos_x][j]=1;
                pos_y-=d;
            }
            else if(c=='E'){
                for(int j=pos_x;j<=pos_x+d;j++)b[j][pos_y]=1;
                pos_x+=d;
            }
            else{
                for(int j=pos_x;j>=pos_x-d;j--)b[j][pos_y]=1;
                pos_x-=d;
            }
        }
        
        int ans=0;

        for(int i=0;i<=20;i++){
            for(int j=0;j<=20;j++){
                if(a[i][j]==1&&b[i][j]==1)ans++;
            }
        }

        if(ans==n)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}
