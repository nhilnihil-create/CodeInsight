//hail to jwalaji
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n,m,maxa=0;
vector<lli> adj[200005];
vector<bool> stat(200005,0);
lli dfs(lli a){
    //cout<<"a : "<<a<<endl;
    stat[a]=1;
    lli temp=0;
for(auto &it: adj[a]){
    if(!stat[it]){
            //cout<<"it : "<<it<<endl;
        stat[it]=1;
        temp+=dfs(it);
    }
}
//cout<<"temp+1 : "<<temp+1<<endl;
return temp+1;
}
lli solve(){
for(lli i=1;i<=n;i++){
    if(!stat[i]){
        maxa=max(maxa,dfs(i));
    }
}
return maxa;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
cin>>n>>m;
//cout<<adj[1].size();
for(lli i=0;i<m;i++){
        lli a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
}
cout<<solve()<<endl;
return 0;
}
