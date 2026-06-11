#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define mset(arr, val) memset((arr), (val), sizeof(arr))
#define For(i, init, n) for (int64_t (i) = (init); (i) < (n); (i)++)
#define ___ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

// const double PI = acos(-1.0), E = exp(1.0), EPS = 1e-9;
const int MOD = (int)1e9 + 7, N = (int)1e5;

int main()
{   
#ifdef MY_PREPROCESSOR
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ___
    
    string s;
    cin >> s;
    int cnt = 0, tmp = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != 'R')
        {
            cnt = max(cnt, tmp);
            tmp = 0;
        }
        else
        {
            tmp++;
        }
    }
    cnt = max(cnt, tmp);
    cout<< cnt;
    
    return 0;
}