//g++  5.4.0

#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

const int nax = 2e5+1;
vector<int> g[nax];
int n;
 
int func(int p , int q )
{
    return p*(n-q+1);
}

signed main()
{
    fast;
    cin >> n;
    int res = n ;
    for(int i=1 ; i<n ; i++ )
    {
        res += i*(n-i+1);
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        res -= func(min(u,v),max(u,v));
    }
       
    cout << res ;
    
}



