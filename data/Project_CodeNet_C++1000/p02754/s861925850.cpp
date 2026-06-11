#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll temp=0;
    if(b||a)
    temp=n/(a+b);
    ll ans=0;
    ans=temp*a;
    if(a)
    ans=ans+min(n%(a+b),a);
    cout<<ans;
}

