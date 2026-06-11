#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long
#define NMAX 200000

#define _LL long long
#define rep(i, n) for(_LL i = 0; i < (_LL)(n); i++)
vector<pair<int,int>> b[NMAX];
int ans[NMAX];
int maxcolor = -1;

void search(int c, int p, int pc)
{
    maxcolor = max(maxcolor, pc);
    int index = 1;
    for( auto itr = b[c].begin(); itr != b[c].end(); itr++ )
    {
        if( itr->first != p ) 
        {
            if( index == pc ) index++;
            ans[itr->second] = index;
            search(itr->first, c, index++);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++ )
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        b[u].push_back(make_pair(v, i));
        b[v].push_back(make_pair(u, i));
    }
    search(0, -1, -1);
    cout << maxcolor << endl;
    for( int i = 0; i < n - 1; i++ ) cout << ans[i] << endl;
}