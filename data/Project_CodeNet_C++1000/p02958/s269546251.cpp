#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 #define hi ios_base :: sync_with_stdio(false); cin.tie(0);cout.tie(0);
int i,j,k,mo;
main()

{
    int n;cin>>n;int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    int c=0;
    for(i=0;i<n;i++)
    {
        if(i+1==a[i]) continue;
        c++;
    }
    if(c<=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
