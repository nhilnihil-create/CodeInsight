/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
double k=(double)n/100;
int f=k;
if(f%2==1)
{
f--;
}
int ans=f/2-1;
cout<<9-ans<<endl;
}