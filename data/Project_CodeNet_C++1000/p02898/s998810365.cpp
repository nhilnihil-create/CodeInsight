#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(x>=k)
        cnt++;
    }
    cout<<cnt<<endl;
}