#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define nl endl
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio;
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        b[a[a[i]-1]-1]=a[i];
    }
     for (int i = 0; i < n; i++)
    {
        cout<< b[i]<<" ";
    }
}