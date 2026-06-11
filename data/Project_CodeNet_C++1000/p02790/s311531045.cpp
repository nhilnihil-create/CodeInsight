#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve()
{
    int a,b,i;
    cin>>a>>b;
    if(a<b){
        for(i=1;i<=b;i++) cout<<a;
        return;
    }
    else{
        for(i=1;i<=a;i++) cout<<b;
        return;
    }
}
int main()
{
    solve();
}