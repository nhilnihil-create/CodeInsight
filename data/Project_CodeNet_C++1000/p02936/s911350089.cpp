#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)


#define NMAX 200000
vector<int> b[NMAX];
int node[NMAX];
int parent[NMAX];
bool flag[NMAX];

void maketree(int c, int p)
{
    parent[c] = p;
    for( auto itr = b[c].begin(); itr != b[c].end(); itr++ )
    {
        if( *itr != p ) 
        {
            maketree(*itr, c);
        }
    }
}

int getvalue(int i)
{
    if( parent[i] < 0 ) return node[i];
    if( !flag[i] )
    {
        node[i] += getvalue(parent[i]);
        flag[i] = true;
    }
    return node[i];
}

int main()
{
    int n, q;
    cin >> n >> q;
    rep(i, n) 
    {
        node[i] = 0;
        flag[i] = false;
    }
    for(int i = 0; i < n - 1; i++ )
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        b[u].push_back(v);
        b[v].push_back(u);
    }
    rep(j, q)
    {
        int p, x; cin >> p >> x; p--;
        node[p] += x;
    }

    maketree(0, -1);

    rep(i, n)
    {
        cout << getvalue(i) << " ";
    }
}