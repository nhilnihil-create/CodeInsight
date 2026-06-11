#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

signed main()
{
    int n,k,s;
    cin>>n>>k>>s;
    int padding;
    if (s == 1000000000)
    {
        padding = s - 1;
    }
    else {
        padding = 1000000000;

    }
    rep(i,k){
        cout << s << " ";
    }
    rep(i,n-k){
        cout << padding << " ";
    }
    cout << endl;
    return 0;
}