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

const int N = 1e5+5;
const int mod = 1e9+7;
ll a[N], b[N], c[N], d, dp, dis;
//pair <int, int> p[N];
char o;
bool mark[N], h;
string s, s1;
//stack <int> st;
//set <ll> st1, st2;
//deque <int> dq;
//vector <int> vt[N];
//int a1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};



int main()
{
    Fast
    ll t, n, m, k = 0, f = 0, sum = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m;
        if (i == 0)
            f = m;
        else{
            f = max(f, m);
            ans +=  f-m;
        }
    }
    cout << ans << endl;
}
