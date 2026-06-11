#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int N;
    int res = 0;
    cin>>N;
    vector<vector<int>> G(N,vector<int>(N,-1));
    for(int i=0;i<N;i++){
        int A;
        cin>>A;
        for(int j=0;j<A;j++){
            int x,y;
            cin>>x>>y;x--;
            G[i][x]=y;
        }
    }
    for(int bit=0;bit<(1<<N);bit++){
        vector<int> honest(N,0);
        for(int i=0;i<N;i++){
           if(1 & (bit >> i))honest[i]=1;
        }
        bool ok=true;
        for(int j=0;j<N;j++){
            if(!honest[j])continue;
            for(int k=0;k<N;k++){
                if(G[j][k]==-1)continue;
                if(G[j][k]!=honest[k])ok=false;
            }
        }
        if(ok)
        {
            res=max(res,accumulate(honest.begin(),honest.end(),0));
        }
    }
    cout<<res; 
    return 0;
}