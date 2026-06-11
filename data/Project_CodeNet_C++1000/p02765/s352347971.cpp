#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<ll>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.14159265
#define pb push_back
#define bits(n) __builtin_popcount(n)

void solve()
{
    int n,r;
    cin>>n>>r;
    if(n>=10)
    cout<<r;
    else
    {
        cout<<r+(100*(10-n));
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w", stdout);
#endif

    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}