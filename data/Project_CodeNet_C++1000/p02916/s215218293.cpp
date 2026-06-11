#include "bits/stdc++.h"
using namespace std;
typedef  long long ll;
const int MAXN=20;
int a[MAXN],b[MAXN],c[MAXN];
int main(){
    int n,ans=0; cin>>n;
    for(int z=0;z<3;z++){
        if(z==2)n--;
     for(int i=0;i<n;i++){
         if(!z)cin>>a[i];
         else if(z==1)cin>>b[i];
         else cin>>c[i];
     }
    }
    for(int i=0;i<n;i++){
        ans+=b[i];
        if(a[i+1]-a[i]==1)
            ans+=c[a[i]-1];
    }
    cout<<ans+b[n];
}