#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    
    string A="";
    string B="";
    
    rep(i,b)
        A+=to_string(a);
    rep(i,a)
        B+=to_string(b);
    
    if(A>B) cout<<B<<endl;
    else cout<<A<<endl;
    
    return 0;
}