#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
#define lcm(x, y) ((x) * (y) / __gcd((x), (y)))
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define debug(x) cout << #x << " : " << x << endl
#define part cout << "----------------------------------\n";
#include <iostream>

/*

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp>     //required
using namespace __gnu_pbds;              //required
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<int> s;
// special `tree` functions:
cout << s.order_of_key(3) << endl;	// the number of elements in s less than 3 (in this case, 0-based index of element 3)
out << *s.find_by_order(1) << endl; // 1-st elemt in s (in sorted order, 0-based)

*/

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; // trick to explore an implicit 2D grid
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // S,SE,E,NE,N,NW,W,SW neighbors  //GO FOR EVEN FOR 4 moves

#define fastinput                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

LL POW(LL x, LL y)
{
    LL ans = 1;
    LL base = x;
    while (y)
    {
        if (y & 1)
        {
            ans *= base;
        }
        base = base * base;
        y = y >> 1;
    }
    return ans;
}

int main()
{
    fastinput;
    LL n,i,j,k,t,temp;
    LL w,h;
    cin>>h>>w;
    if(h==1 || w==1)
    {
        cout<<1<<endl;
        return 0;
    }
    LL ans=h*w;
    ans/=2;
    ans+=(h*w)%2;
    cout<<ans<<endl;

    return 0;
}
