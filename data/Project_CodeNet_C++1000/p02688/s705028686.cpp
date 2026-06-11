#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

int main(void)
{
    ll n,k,d;
    cin >> n >> k;
    ll a[n]={};
    for(int j=0;j<k;j++)
    {
        cin >> d;
        for(int i=0;i<d;i++)
        {
            ll x;
            cin >> x;
            a[x-1]=1;
        }
    }
    ll count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
