#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int elevation[n+1];
    vector<int> susjed[n+1];
    for(int i=1;i<=n;i++){
        cin>>elevation[i];
    }
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        susjed[x].push_back(y);
        susjed[y].push_back(x);
    }
    int rj=0;
    for(int i=1;i<=n;i++){
        bool t=true;
        for(int j=0;j<susjed[i].size();j++){
            if(elevation[i]<=elevation[susjed[i][j]]){
                t=false;
                break;
            }
        }
        if(t){
            rj++;
        }
    }
    cout << rj<<endl;
}
