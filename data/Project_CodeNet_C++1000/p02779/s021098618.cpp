#include <bits/stdc++.h>
#define ll long long
#define L long
#define endl "\n"
#define mset(x, val) memset(x, val, sizeof(x))
#define For(i, init, n) for (ll int i = init; i < n; i++)
#define ___ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const double PI = acos(-1.0), E = exp(1.0), EPS = DBL_EPSILON;
const ll int MOD = (ll int)1e9 + 7, N = (ll int)1e5;

int main()
{   
#ifdef MY_PREPROCESSOR
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ___
    
    int n;
    cin >> n;
    int x;
    set<int> st;
    while (n--)
    {
        cin >> x;
        if (st.find(x) == st.end())
            st.insert(x);
        else
        {
            cout<< "NO";
            return 0;
        }
    }
    cout<< "YES";
    
    return 0;
}