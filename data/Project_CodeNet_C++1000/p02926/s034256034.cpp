#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
typedef long double ld;
//typedef tree <int,null_type,less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define FAST                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define rep(g, i, n) for (ll g = i; g < n; g++)
#define rev(g, n, i) for (ll g = n - 1; g >= i; g--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define ve vector
#define bb break
#define cc continue
#define rem 1000000007
#define PI 3.141592653589793238462643383279502
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
struct point
{
    ll x, y;
    double ang;
};
bool fun(point a,point b)
{
    return a.ang<b.ang;
}
int main()
{
    FAST
        // freopen("input1.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        /*ll tests;
    cin>>tests;
    rep (gg,0,tests)
    {}*/
        ll n;
    cin >> n;
    ve<point> arr(n);
    rep(i, 0, n)
    {
        cin >> arr[i].x >> arr[i].y;
        if (arr[i].x>0&&arr[i].y>=0)
        {
            arr[i].ang=atan((double)arr[i].y/arr[i].x);
        }
        else if (arr[i].x<0&&arr[i].y>=0)
        {
            double val=(double)(arr[i].x)/arr[i].y;
            arr[i].ang=atan(abs(val))+PI/2;
        }
        else if (arr[i].x<0&&arr[i].y<=0)
        {
            double val=(double)(arr[i].y)/arr[i].x;
            arr[i].ang=atan(abs(val))+PI;
        }
        else if (arr[i].x>0&&arr[i].y<=0)
        {
            double val=(double)(arr[i].x)/arr[i].y;
            arr[i].ang=atan(abs(val))+3*PI/2;
        }
        else if (arr[i].x==0)
        {
            if (arr[i].y>=0)
            {
                arr[i].ang=PI/2;
            }
            else
            {
                arr[i].ang=3*PI/2;
            }
        }
    }
    sort(all(arr),fun);
    rep (i,0,n)
    {
        arr.pb(arr[i]);
    }
    ll ans = 0;
    rep(i, 1, n+1)
    {
        rep (j,0,2*n+1-i)
        {
            ll ax=0,ay=0;
            rep (z,j,j+i)
            {
                ax+=arr[z].x;
                ay+=arr[z].y;
            }
            ll ans1=ax*ax+ay*ay;
            ans=max(ans,ans1);
        }
    }
    double fans = sqrt(ans);
    cout << fixed << setprecision(25) << fans << "\n";
}
