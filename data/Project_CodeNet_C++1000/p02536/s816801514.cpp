#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cctype>
using namespace std;
typedef long long ll;
typedef vector<int> veci;
typedef vector<ll> vecl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <class T>
inline void read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return ;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1:1;
    ret = (c == '-') ? 0:(c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return ;
}
inline void outi(int x) {if (x > 9) outi(x / 10);putchar(x % 10 + '0');}
inline void outl(ll x) {if (x > 9) outl(x / 10);putchar(x % 10 + '0');}

int n,m;
const int N=1e5+7;
int x,y;
int parent[N];
using namespace std;
void Init()
{
    for(int i = 1;i <= n;i++)
        parent[i] = i;
    return;
}

int get_boss(int v)
{
    if(parent[v] == v)
        return v;
    else
    {
        //路径压缩(使搜索祖宗的过程中，路径中搜索的结点的父亲的变为祖宗)
        parent[v] = get_boss(parent[v]);
        return parent[v];
    }
}

void Merge(int v,int u)
{
    int t1 = get_boss(v);
    int t2 = get_boss(u);
    parent[t2] = t1;
    return;
}
int main()
{
    int cnt=0;
    cin>>n>>m;
    Init();
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        Merge(x,y);
    }
    for(int i=1;i<=n;i++)
    {
       // cout<<parent[i]<<" ";
        if(parent[i]==i)
            cnt++;
    }
    cout<<cnt-1<<endl;
}
