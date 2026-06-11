#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1; i<n; ++i){
        int a,b;
        a=i;
        b=(n-1)/a;
        ans+=b;
    }
    cout<<ans<<"\n";
}

