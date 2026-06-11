/*
h s, d't skp th si tll i's sved
 * ABC141 E
 * ABC145 D
 * ABC147 F
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ll a,b,k;
cin>>a>>b>>k;
ll h=max(0ll,a-k);
k=max(0ll,k-a);
b=max(0ll,b-k);
cout<<h<<" "<<b<<endl;
}