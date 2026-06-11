#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    string s,t,u;
    int a,b;
    cin>>s>>t;
    cin>>a>>b;
    cin>>u;
    
    if(s==u) cout<<a-1<<" "<<b<<endl;
    else if(t==u) cout<<a<<" "<<b-1<<endl;
    
    return 0;
}