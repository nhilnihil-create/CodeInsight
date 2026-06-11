#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR0(i,n) for(i=0;i<n;i++)
#define FOR(i,j,n) for(i=j;i<n;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inf 1000000000
#define ninf -1000000000
#define endl '\n' 
#define she_told_me_dont_worry ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// Use cout.flush() for interactive problems.
// Use this for increased stack size: g++ -o a.exe -Wl,--stack=256000000 -O2 source.cpp
inline long long  MAX2(long long  a, long long int b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< ii > vii;
bool compare(pll l, pll r)
{
    double al = atan2((double)l.ss, (double)l.ff);
    double ar = atan2((double)r.ss, (double)r.ff);
    //cout<<al<<" "<<ar<<endl;
    return al<ar;
}
double dis(pll a)
{
    double dis = sqrt(a.ff*a.ff + a.ss*a.ss);
    return dis;
}
int main()
{
    she_told_me_dont_worry
    int n;
    cin>>n;
    int i;
    vector< pll > co;
    FOR0(i, n)
    {
        pll temp;
        cin>>temp.ff>>temp.ss;
        co.pb(temp);
    }
    sort(co.begin(), co.end(), compare);
    FOR0(i, n) co.pb(co[i]);
    // FOR0(i, 2*n)
    // {
    //     cout<<co[i].ff<<" "<<co[i].ss<<" "<<atan2(co[i].ss, co[i].ff)<<endl;
    // }
    FOR(i, 1, 2*n)
    {
        co[i].ff += co[i-1].ff; co[i].ss += co[i-1].ss;
    }
    int j;
    double ans = -1;
    FOR0(i, n)
    {
        pll left = co[i];
        FOR(j, i, i+n)
        {
            pll cur = co[j];
            if(i > 0)
            {
                cur.ff -= co[i-1].ff;
                cur.ss -= co[i-1].ss;
            }
            if( ans < dis(cur))
                ans = dis(cur);
        }
    }
    cout<<fixed<<setprecision(20)<<ans<<endl;
    cerr <<endl<< "Time elapsed : " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
}