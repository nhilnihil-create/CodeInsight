#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X,Y;cin>>N>>X>>Y;
    X--;
    Y--;
    vector<vector<int>> connect(N,vector<int>(0));
    for(int i=0;i<N-1;i++){
        connect[i].push_back(i+1);
        connect[i+1].push_back(i);
    }
    connect[X].push_back(Y);
    connect[Y].push_back(X);
    vector<int> count(N,0);
    for(int i=0;i<N;i++){
        queue<int> q;q.push(i);
        vector<int> check(N,-1);
        check[i]=0;
        int c=1;
        while(q.size()!=0){
            int a=q.front();
            q.pop();
            for(int j=0;j<connect[a].size();j++){
                if(check[connect[a][j]]==-1){
                    q.push(connect[a][j]);
                    check[connect[a][j]]=check[a]+1;
                    count[check[connect[a][j]]]++;
                }
            }
        }
    }
    for(int i=1;i<N;i++)cout<<count[i]/2<<endl;
}