#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    ll n,i,c,d;
    cin>>n;
    ll p[n];
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    d=p[0];c=1;
    for(i=1;i<n;i++){
        if(p[i]<=d){
            c++;d=p[i];
        }
    }
    cout<<c<<endl;return;
}
int main()
{
    solve();
}