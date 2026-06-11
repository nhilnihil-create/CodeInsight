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
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i=0;i<n;i++)
    {
        string temp;
        cin>>temp;
        mp[temp]++;
    }
    int maxi=INT_MIN;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>maxi)
        maxi=it->second;
    }
    for (auto it = mp.begin(); it!=mp.end(); it++)
    {
        if(it->second==maxi)
        cout<<it->first<<"\n";
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