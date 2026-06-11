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

ll t1,t2,a1,a2,b1,b2;

int main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if(a1==b1 || a2==b2 || a1*t1+a2*t2==b1*t1+b2*t2)
    {
        cout << "infinity" << endl;
        return 0;
    }
    ll x = (a1-b1)*t1;
    ll y = (a2-b2)*t2;
    if(x<0)
    {
        x = -x;
        y = -y;
    }
    if(y>-x)
    {
        cout << 0 << endl;
        return 0;
    }
    ll cha = -(x+y);
    if(x%cha == 0)
    {
        cout << (x/cha) * 2 << endl;
    }
    else cout << (x/cha) * 2 + 1 << endl;
}
