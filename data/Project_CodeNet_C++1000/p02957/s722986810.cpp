#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 #define hi ios_base :: sync_with_stdio(false); cin.tie(0);cout.tie(0);
int i,j,k,mo;
main()

{
    int n,m;
    cin>>n>>m;
    if(n==m) cout<<0<<endl;
    else if((n+m)%2==0)
    {
        cout<<(n+m)/2<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}
