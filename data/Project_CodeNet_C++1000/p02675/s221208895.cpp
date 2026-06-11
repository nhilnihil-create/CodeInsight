#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree < int,  null_type,  less<int>,  rb_tree_tag,  tree_order_statistics_node_update > ordered_set;
typedef long long ll;
#define pb push_back
#define pi (acos(-1))
#define ull  unsigned long long
#define ld long double
#define all(v) v.begin(), v.end()
///freopen("input.txt","r",stdin);
///freopen("output.txt","w",stdout);
ll LCM(ll a, ll b)
{
    ll g = __gcd(a,b);
    return (a/g)*b ;
}
string numtostr(ll n)
{
    ostringstream str1 ;
    str1 << n ;
    return str1.str();
}
ll strtonum(string s)
{
    ll x ;
    stringstream str1(s);
    str1 >> x ;
    return x ;
}
short n;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   cin>>n;
   if(n%10==2||n%10==4||n%10==5||n%10==7||n%10==9)
    cout<<"hon\n";
   else if(n%10==3)
    cout<<"bon\n";
   else
    cout<<"pon\n";
    return 0;
}
