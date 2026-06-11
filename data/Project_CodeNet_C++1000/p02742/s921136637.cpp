#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,ans,ans1;
    cin>>n>>m;
    if(n==1||m==1)
        {cout<<"1"<<endl;return 0;}
    if(m%2==0)
        {ans=m/2;
        ans1=m/2;}
    else
        {ans=m/2+1; 
        ans1=m/2;}
    if(n%2==0)
        cout<<(ans*(n/2))+(ans1*(n/2))<<endl;
    else
        cout<<(ans*(n/2+1))+(ans1*(n/2))<<endl;
    return 0;
}