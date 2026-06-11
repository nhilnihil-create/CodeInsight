#include<bits/stdc++.h>
using namespace std;
long long sum;int i,j,n;
int main()
{cin>>n;
for(i=1;i<=n;i++){for(j=1;i*j<=n;j++)sum+=(i*j);}
cout<<sum;}