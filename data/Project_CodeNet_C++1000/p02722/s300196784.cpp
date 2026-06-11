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

ll n;
vector<ll> v;
void fact(ll x)
{
    v.clear();
    for(ll i = 1; i*i<=x; i++) if(x%i == 0) v.pb(i);
    if(v[v.size()-1] * v[v.size()-1] == x)
    {
        int sz = v.size();
        for(int i = sz-2; i>=0; i--) v.pb(x / v[i]);
    }
    else
    {
        int sz = v.size();
        for(int i = sz-1; i>=0; i--) v.pb(x / v[i]);
    }
}
unordered_set<ll> m;


int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin >> n;
    fact(n);
    for(int i = 1; i<v.size(); i++)
    {
        ll cur = n;
        while(cur % v[i] == 0) cur /= v[i];
        if(cur % v[i] == 1) m.insert(v[i]);
    }
    fact(n-1);
    for(int i = 1; i<v.size(); i++)
    {
        m.insert(v[i]);
    }
    cout << m.size() << endl;
}
