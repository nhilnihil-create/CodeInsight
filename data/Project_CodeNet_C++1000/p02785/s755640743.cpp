#include <bits/stdc++.h>

using namespace std;

#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define PI 3.14159265
#define pb push_back
#define bits(n) __builtin_popcount(n)
#define ll long long int

void solve()
{
    int n,k;
    cin>>n>>k;
    maxpq s;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        s.push(temp);
    }
    if(k>=n)
    cout<<"0";
    else{
    while(k--)
    {
        s.pop();
    }
    ll sum=0;
    while(!s.empty())
    {
        sum+=s.top();
        s.pop();
    }
    cout<<sum;
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