#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &books,int c,int idx,vector<int> tmp){
    int i;
    for(i=0;i<tmp.size();i++){
        if(tmp[i]<c){        
            break;    
        }
    }
    if(i==tmp.size()) return 0;
    if(idx == books.size()) return INT_MAX;

    int a = dfs(books,c,idx+1,tmp);

    for(int i=0;i<tmp.size();i++){
        tmp[i]+=books[idx][i+1];
    }
    int b = dfs(books,c,idx+1,tmp);
    if(b!=INT_MAX) b +=books[idx][0];

    return min(b,a);
}

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<vector<int>> books(n,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            cin>>books[i][j];
        }
    }
    int cc;
    int cost = dfs(books,x,0,vector<int>(m,0));
    if(cost==INT_MAX) cout<<-1;
    else cout<<cost;
}