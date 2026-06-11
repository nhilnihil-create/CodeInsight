#include<bits/stdc++.h>
//#include<tr1/unordered_map>
#pragma GCC optimize ("Ofast")
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define forn(i, n) for(int i=0; i<int(n); i++)
#define Forn(i, n) for(int i=1; i<=int(n); i++)

using namespace std;

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;*/

int n, k, c;
bool can[200010];
int nxt[200010];
int suf[200010];
vector<int> v;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin >> n >> k >> c;
    Forn(i, n)
    {
        char x;
        cin >> x;
        if(x == 'o') can[i] = 1;
    }
    int now = -1;
    for(int i=n; i>=1; i--)
    {
        nxt[i] = now;
        if(can[i]) now = i;
    }
    for(int i=n; i>=1; i--)
    {
        if(!can[i])
        {
            if(nxt[i] == -1) suf[i] = 0;
            else suf[i] = suf[nxt[i]];
            //cout << "x " << nxt[i] << " " << suf[i] << endl;
        }
        else
        {
            int j = i+c+1;
            if(j>n) suf[i] = 1;
            else suf[i] = 1 + suf[j];
            //cout << "o " << j << " " << suf[j] << endl;
        }
    }
    int nowtake = 0;
    int lasttake = -100;
    int ans = 0;
    Forn(i, n)
    {
        if(can[i] && i - lasttake > c)
        {
            if(suf[i+1] + nowtake < k) v.pb(i);
            nowtake++;
            lasttake = i;
        }
    }
    forn(i, v.size()) cout << v[i] << '\n';
}
