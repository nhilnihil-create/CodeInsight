#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
    int n;
    cin>>n;
    
    double ans=ceil(n/1.08);
    
    if(floor(ans*1.08)==n) cout<<ans<<endl;
    else cout<<":("<<endl;
    
    return 0;
}