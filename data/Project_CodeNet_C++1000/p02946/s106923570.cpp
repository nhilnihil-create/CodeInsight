#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define val 1000000000000000000
using namespace std;
int main()
{
    ll k,x;
    cin>>k>>x;
    ll l1,l2;
    l1=x-k+1;
    l2=x+k-1;
    for(int i=l1;i<=l2;i++)
    cout<<i<<" ";
    cout<<endl;
}