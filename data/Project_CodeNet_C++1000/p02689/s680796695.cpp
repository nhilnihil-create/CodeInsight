#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int M;
    cin>>M;
    vector<int> h(n+10,0);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    vector<int> m[n+10];
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=0;j<m[i].size();j++){
            if(h[i]<=h[m[i][j]]){
                flag=false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return(0);
}