
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int MOD = 1e9+7,mxN = 50,INF = 1e9;
int n=2,q;


void solve()
{
    cin>>n;
    char a[n],b[n],s[n*2];
    cin >> a >> b;
    int i = 0,j=0;
    for(int k=0;k<n*2;k++)
    {
        if(k&1)
            s[k]=b[j],j++;
        else s[k] = a[i],i++;
    }
    s[n*2]=0;
    cout << s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    
}
