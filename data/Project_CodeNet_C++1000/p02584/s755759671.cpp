#include <iostream>
#include <fstream>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <cstring>
#include <sstream>
#include <complex>

#define f first
#define s second
#define ll long long
#define ld double
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define y0 eto
#define y1 mezhdy
#define y2 nami
#define left extermination
#define right dismemberment
 
using namespace std;
 
double start_moment = 0;
double get_runtime() { return 1.0*clock()/CLOCKS_PER_SEC; }
void reset_timer() { start_moment = get_runtime(); }
double timer_time() { return get_runtime() - start_moment; }
void runtime(){cout<<fixed<<setprecision(5)<<get_runtime()<<'\n';}
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
template <class T>void read(vector<T> &a,ll n){T x; a.clear();for(ll i=0;i<n;i++){cin>>x;a.pb(x);}}
template <class T>void write(vector<T> &a){for(T x : a) cout<<x<<' ';cout<<'\n';}

ll x1,d1,k1;

int sgn(ll f)
{
    return f>0;
}

__int128 abs(__int128 x)
{
    if(x<0)
        return -x;
    return x;
}

void out(__int128 ans)
{
    vector<int> dg;
    while(ans)
    {
        dg.pb(ans%10);
        ans/=10;
    }
    reverse(all(dg));
    if(dg.empty()) dg.pb(0);
    
    for(int i=0;i<dg.size();i++)
        cout<<dg[i];
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
//    freopen("INPUT.txt","r",stdin);
//    freopen("OUTPUT.txt", "w", stdout);
    
    cin>>x1>>k1>>d1;
    
    __int128 d=d1;
    __int128 x=x1;
    __int128 k=k1;
    
    __int128 f1=x-d*k;
    __int128 f2=x+d*k;
    __int128 ans=min(abs(f1),abs(f2));
    
    if(sgn(f1)!=sgn(f2))
    {
        __int128 lft=abs(x)%d;
        __int128 cnt=(abs(x)-lft)/d;

        if((k-cnt)%2==0)
            ans=min(ans,abs(lft));
        else
            ans=min(ans,abs(lft-d));
    }
    
    out(ans);
}
