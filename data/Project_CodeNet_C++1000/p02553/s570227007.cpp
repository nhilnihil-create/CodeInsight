#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long 
ll a,b,c,d;
ll ans=-1000000000000000000;
int main(){
    cin>>a>>b>>c>>d;
    ans=max(ans,a*c);
    ans=max(ans,a*d);
    ans=max(ans,b*c);
    ans=max(ans,b*d);
    cout<<ans;
    return 0;
}