#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,m,h[100005],a,b,ans=0;
    bool c[100005]={};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;
        b--;
        if(h[a]>h[b]){
            c[b]=true;
        }
        else if(h[a]<h[b]){
            c[a]=true;
        }
        else{
            c[a]=true;
            c[b]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(!c[i])
            ans++;
    }
    cout<<ans<<endl;
    return(0); 
}
