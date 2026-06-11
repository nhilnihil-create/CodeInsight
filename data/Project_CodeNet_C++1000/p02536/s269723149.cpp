/*
*                                 Name : chaitanya
*
*                         Institute : ANITS,Visakhapatnam
*   "Don't regret anything you do, because in the end it makes you who you are."
*
*/
#include<cstdio>
#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<complex>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<numeric>
#include<limits>
#include<climits>
#include<cfloat>
#include<functional>
#include<iterator>
#include <random>
#include<sstream>
#include <assert.h>
#define infy  1000000000
#define all(x) begin(x),end(x)
#define ll long long int
#define ff first
#define ss second
#define pb push_back
const ll m = 1000000007;
using namespace std;

map <int,int>mp;
vector < int > g[100010],t(100010);
bool vis[100010];

void dfs(int s)
{   
    vis[s] = true;
    mp[s] = 1;
    for (int i = 0; i < g[s].size(); ++i)
    {
        if( !vis[g[s][i]])
            dfs(g[s][i]);
    }
}

int main()
{  
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        t[i] = i;
    }
    int c = 0;
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < n; ++i)
    {
        if( mp[i] == 0)
        {
            c++;
            mp[i] = 1;
            dfs(i);
        }
    }
    cout << c-1 << "\n";
    return 0;
}
