#include <bits/stdc++.h>
using namespace std;
 int main()
{
    int n,x,t;
    cin>>n>>x>>t;
    int cnt=(n/x);
    if(n%x==0){cout<<cnt*t;}
    else{cout<<(cnt+1)*t;}
}
