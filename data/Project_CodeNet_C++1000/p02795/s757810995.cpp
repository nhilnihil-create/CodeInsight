#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007 
using namespace std;
const int mxN=200000;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int h,w,n;
cin>>h>>w>>n;
int ans=n/max(h,w);
if(n%max(h,w)!=0)
{
ans++;
}
cout<<ans<<endl;
}