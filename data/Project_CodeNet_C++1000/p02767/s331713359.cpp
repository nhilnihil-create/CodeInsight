#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans=1000000009;
    int vmax=0;
    cin>>n;
    int x[110]={};
    for(int i=0;i<n;i++){
        cin>>x[i];
        vmax=max(vmax,x[i]);
    }
    for(int p=1;p<=vmax;p++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=pow(x[i]-p,2);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<"\n";
    return(0);
}