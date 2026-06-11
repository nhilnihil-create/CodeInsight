/*
author : seryu
title : AGC034A_"Kenken Race"
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define mrep(i,j,n) for(int i = j; i < n; i++)
#define mreps(i,j,n) for(int i = j; i <= n; i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(all(x), val), x.end())
typedef long long ll;
typedef pair<int, int> P;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
ll MOD = 1000000007;
int INF = 1001001001;

void solve()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    a--;b--;c--;d--;
    cin >> s;
    for (int pos = a; pos + 2< c; pos++)
    {
        if(s[pos+1] == '#' && s[pos+2] == '#')
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int pos = b; pos + 2 < d; pos++)
    {
        if(s[pos+1] == '#' && s[pos+2] == '#')
        {
            cout << "No" << endl;
            return;
        }
    }
    
    bool ok = false;
    if(c < d)
    {
        ok = true;
    }
    else if(c > d)
    {
        for(int pos = b; pos <= d ; pos++)
        {
            if(s[pos-1] == '.' && s[pos] == '.' && s[pos+1] == '.')
            {
                ok = true;
                break;
            }
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return;	
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
