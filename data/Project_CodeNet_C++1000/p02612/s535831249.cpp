#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin>>n;
    int a=n/1000;
    n-=(a)*1000;
    if(n){cout<<1000-n;}else{cout<<"0";}
}
int main()
{
    solve();
}
