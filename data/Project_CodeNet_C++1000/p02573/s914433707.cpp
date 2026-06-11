//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
#define free  freopen ("input.txt", "r", stdin);freopen ("output.txt", "w", stdout);
#define Fast  ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define mp make_pair
#define F first
#define S second

bool vowel(char che)
{
    if (che == 'A' || che == 'E' || che == 'I' || che == 'O' || che == 'U' || che == 'Y')
        return true;
    else
        return false;
}

const int N = 2e7+5;
const int mod = 1e9+7;
int a[N], b[N], c, d, dp, dis = 0;
pair <int, int> p[N];
char o;
bool mark[N], h;
//string s, s1;
//stack <int> st;
//set <ll> st1, st2;
//deque <int> dq;
vector <int> vt[N];
//int a1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void dfs(ll v)
{
    dis++;
    mark[v] = true;
    for (int i = 0; i < vt[v].size(); i++){
        if (!mark[vt[v][i]]){
            dfs(vt[v][i]);
        }
    }
}
int main()
{
    Fast
    ll t, n, m, k = 0, f = 0, sum = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> p[i].F >> p[i].S;
        if (p[i].F > p[i].S)
            swap(p[i].F, p[i].S);
    }
    sort (p, p+m);
    for (int i = 1; i <= m; i++){
        if (p[i].F != p[i-1].F || p[i].S != p[i-1].S){
            vt[p[i-1].F].pb(p[i-1].S);
            vt[p[i-1].S].pb(p[i-1].F);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++){
        if (!mark[i]){
            dis = 0;
            dfs(i);
        }
        mx = max(mx, dis);
    }
    cout << mx;
}
