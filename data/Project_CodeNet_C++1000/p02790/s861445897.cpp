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
    char a,b;
    cin>>a>>b;
    string a1="",b1="";
    for(int i=0;i<(int)(b-48);i++)
    {
        a1+=a;
    }
    for(int i=0;i<(int)(a-48);i++)
    {
        b1+=b;
    }
    if(a1>b1)
    cout<<b1;
    else
    {
        cout<<a1;
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