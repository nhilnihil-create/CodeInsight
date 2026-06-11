#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define endl "\n"
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
const int N = 2e5 + 10;
const ll inf = 1e18 + 10, mod = 1e9 + 7;
int n;
pair <ll, ll> a[N];
ll ansll, anslr, ansrl, ansrr;
int main()
{
    ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("lca_rmq.in", "r", stdin);
    //freopen("lca_rmq.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].f >> a[i].s;
    }
    sort(a + 1, a + 1 + n);
    if(n % 2)
    {
        ansll = a[(n + 1) / 2].f;
        anslr = a[(n + 1) / 2].s;
    }
    else
    {
        ansll = (a[n / 2].f + a[n / 2 + 1].f);
        anslr = (a[n / 2].s + a[n / 2 + 1].s);
    }
    for(int i = 1; i <= n; i++)swap(a[i].f, a[i].s);
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    if(n % 2)
    {
        ansrl = a[(n + 1) / 2].s;
        ansrr = a[(n + 1) / 2].f;
    }
    else
    {
        ansrl = (a[n / 2].s + a[n / 2 + 1].s);
        ansrr = (a[n / 2].f + a[n / 2 + 1].f);
    }
    if(anslr >= ansrl)cout << ansrr - ansll + 1;
    else cout << anslr - ansll + ansrr - ansrl + 2;

}















