#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
ll gcd(ll a,ll b)
{
	return b==0 ? a : gcd(b,a%b);
}
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
template<typename T> void debug(T x)
{
    cout<<"value="<<x<<endl;
    return;
}
vector<pair<ll,ll> > factorize(ll n)
{
    vector<pair<ll,ll> > res;
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        res.emplace_back(i,0);
        while(n%i==0){
            n/=i;
            res.back().second++;
        }
    }
    if(n!=1) res.emplace_back(n,1);
    return res;
}
signed main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
	ll A,B;
	while(cin>>A>>B){
        if(gcd(A,B)==1) cout<<1<<endl;
        else{
            ll mxgcd=gcd(A,B);
            vector<pair<ll,ll> > ans=factorize(mxgcd);
            if(ans.size()==0) ans.emplace_back(1,0);
            cout<<ans.size()+1<<endl;
        }
	}
	return 0;
}
