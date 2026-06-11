#include<bits/stdc++.h>
using namespace std;   
int main(){
    int n,a[30],b[30],c[30],ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        ans+=b[a[i]-1];
        if(a[i-1]+1==a[i])
            ans+=c[a[i-1]-1];
    }
    cout<<ans<<endl;
    return 0;
}