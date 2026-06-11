
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9+7,mxN = 50,INF = 1e9;
int n=2,q;


void solve()
{
    vi a(3,1);
    while(n--)
    {
        int k;
        cin>>k;
        a[k-1]=0;
    }
    for(int i=0;i<=2;i++)
        if(a[i])
            cout<<i+1;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
}
