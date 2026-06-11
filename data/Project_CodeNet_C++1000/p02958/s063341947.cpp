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
    int n,k=0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i]!=i+1)
            k++;
    }
    if(k==0||k==2)
        cout<<"YES";
    else
    {
        cout<<"NO";
    }
    
}