#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;cin>>n>>m;
    vector<int>h(n);
    vector<bool>flag(n,true);
 
    for(int i=0;i<n;i++){
      cin>>h[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(h[a]>=h[b]){
          flag[b]=false;
        }
        if(h[a]<=h[b]){
          flag[a]=false;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
      ans+=flag[i];
    } 
    cout<<ans<<endl;
}