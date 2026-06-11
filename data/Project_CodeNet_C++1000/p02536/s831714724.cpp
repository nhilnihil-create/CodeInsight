#include<bits/stdc++.h>
using namespace std;
vector<int>v[100010];
bool vi[100010];
void dfs(int n){
    if(vi[n])return;
    vi[n] = true;
    for(int i=0;i<v[n].size();i++){
        dfs(v[n][i]);
    }
    return;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!vi[i]){dfs(i);cnt++;}
    }
    printf("%d\n",--cnt);
    return 0;
}