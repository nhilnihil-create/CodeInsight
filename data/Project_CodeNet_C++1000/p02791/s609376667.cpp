#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
    ll n,i,j,k,c=0,min=10000000000;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=min){
            min=a[i];c++;}
    }
    cout<<c;
}
