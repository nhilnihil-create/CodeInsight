#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    
    int row,col,thres;
    cin>>row>>col>>thres;

    vector<vector<int>> matrix(row, vector<int>(col));

    vector<int> c(row);

    for(int i=0;i<row;i++) {
        int cost;
        cin>>cost;
        c[i]=cost;
        for(int j=0;j<col;j++) {
            int num;
            cin>>num;
            matrix[i][j]=num;
        }
    }

    int all=1<<row;
    int ans=12345678;

    for(int mask=0;mask<all;mask++) {
        vector<int> level(col);
        int total_cost=0;

        for(int i=0;i<row;i++) {
            if((mask>>i)&1) {
                total_cost+=c[i];
                for(int j=0;j<col;j++) {
                    level[j]+=matrix[i][j];
                }
            }
        }

        bool ok=true;
        for(int z=0;z<level.size();z++) {
            if(level[z]<thres) ok=false;
        }

        if(ok) ans=min(ans,total_cost);
    }

    if(ans==12345678) cout<<-1<<endl;
    else cout<<ans<<endl;

}


