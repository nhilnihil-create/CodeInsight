#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,m,x;
    cin>>n>>m>>x;

    vector<vector<int>> matrix(n,vector<int>(m));
    vector<int> costs(n);

    for(int i=0;i<n;i++) {
        int c;
        cin>>c;
        costs[i]=c;
        for(int j=0;j<m;j++) {
            int num;
            cin>>num;
            matrix[i][j]=num;
        }
    }

    int all=1<<n;
    int ans=123456789;

    for(int mask=0;mask<all;mask++) {
        vector<int> levels(m);
        int total_cost=0;
        for(int i=0;i<n;i++) {
            if((mask>>i)&1) {
                total_cost+=costs[i];
                for(int j=0;j<m;j++) {
                    levels[j]+=matrix[i][j];
                }
            }
        }
        bool ok=true;
        for(int i=0;i<m;i++) {
            if(levels[i]<x) {
                ok=false;
            }
        }

        if(ok) {
            ans=min(ans, total_cost);
        }
    }
    if(ans==123456789) {
        cout<<-1<<endl;
    }
    else {
        cout<<ans<<endl;
    }

    

}


