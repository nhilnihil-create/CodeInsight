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

const int N = 3e5+5;
const int mod = 1e9+7;
ll a[N], b[N], c[N], d, dp1, dis;
char o;
bool mark[N], h;
string s;
//set <ll> st1, st2;
//deque <int> dq;
//vector <ll> vm, vp, vt[N];
//int a1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int main()
{
    Fast
    ll t, n, m, k = 0, f = 0, sum = 0, ans = 0;
    cin >> n >> m >> k >> f;
    ans = max (m*f, k*n);
    sum = max (m*k, n*f);
    cout << max(ans, sum)  << endl;
}
