#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p[n];
    vector<int> vmin(n,0);
    cin>>p[0];
    vmin[0]=p[0];
    int ans=1;
    for(int i=1;i<n;i++){
        cin>>p[i];
        vmin[i]=min(p[i],vmin[i-1]);
        if(p[i]<vmin[i-1]){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return(0);
}