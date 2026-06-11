#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, j, sum, x;
    vector <ll> v;
    cin >> n;
    ll N[n];
    for(i=0;i<n;i++)
    {
        cin >> N[i];
    }
    sort(N,N+n);
    for(i=N[0];i<=N[n-1];i++)
    {
        sum = 0;
        for(j=0;j<n;j++)
        {
            x = (N[j] - i)*(N[j] - i);
            sum = sum + x;
        }
        v.push_back(sum);
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    return 0;
}