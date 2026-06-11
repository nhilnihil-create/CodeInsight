#include<bits/stdc++.h>
using namespace std;

int find_par(vector<int> &par, int ver){
    if(par[ver] == ver)return ver;
    return par[ver] = find_par(par,par[ver]);
}
void make(vector<int> &par,int x,int y){
    int px = find_par(par, x);
    int py = find_par(par, y);
    par[px] = py;
}
int main(){

    int n,m;
    cin>>n>>m;
    vector<int> par(n+1);
    for(int i=0; i <= n;i++)par[i] = i;
    while(m--){
        int x,y;
        cin>>x>>y;
        make(par, x, y);
    }
    map<int, int> mp;
    for(int i=1;i<=n;i++){
        mp[find_par(par, i)]++;
    }
    int ans = -1;
    for(auto it:mp){
        ans = max(ans, it.second);
    }
    cout<<ans<<endl;
}
