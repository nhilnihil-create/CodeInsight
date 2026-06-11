#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pi acos(-1.0)

#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pf(a) printf("%lld\n",a)

#define stll(a) stoll(a,nullptr,10)
#define all(a) a.begin(),a.end()
#define PII pair<ll,ll>
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define EL printf("\n")
#define ff first
#define ss second
#define rev(a) reverse(all(a))


#define mem(ar,val) memset(ar,val,sizeof(ar))
#define ssort(ar) sort(ar.begin(),ar.end())
#define csort(ar,comp) sort(ar.begin(),ar.end(),comp)

#define bug1(a) cout<<"test "<<a<<endl;
#define bug2(a,b) cout<<"test "<<a<<" "<<b<<endl;
#define bug3(a,b,c) cout<<"test "<<a<<" "<<b<<" "<<c<<endl;
#define bug4(a,b,c,d) cout<<"test "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

#define fout freopen("output.txt","w",stdout)
#define fin  freopen("input.txt","r",stdin)

/// unordered_map<int,int>mp;
/// mp.reserve(1024);
/// mp.max_load_factor(0.25);

/// pbds
/// *find_by_order(k) - return k th largest element.. 0 based
/// order_of_key(k) - number of items strictly smaller than k

/*
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return (size_t) x.first * 37U + (size_t) x.second;
  }
};
*/

typedef long long ll;
typedef unsigned long long ull;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


int main()
{
    ll n,k;
    string st;
    cin>>n>>k>>st;
    ll ans =0;
    for(int i=0;i<n-1;i++)
        if(st[i]==st[i+1])
            ans++;
    cout<<min(n-1,ans+2*k)<<endl;

}













