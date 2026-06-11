#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,q,ans;
vector<int> a,b,c,d;

void dfs(vector<int> v){
    if((int)v.size()==n+1){
        int sum=0;
        for(int i=0;i<q;i++){
            if(v[b[i]]-v[a[i]]==c[i]) sum+=d[i];
        }
        ans=max(ans,sum);
        return;
    }
    v.push_back(v.back());
    while(v.back()<=m){
        dfs(v);
        v.back()++;
    }
}

int main(){
    cin>>n>>m>>q;
    a=b=c=d=vector<int>(q);
    for(int i=0;i<q;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    dfs(vector<int>(1,1));
    cout<<ans<<endl;
}