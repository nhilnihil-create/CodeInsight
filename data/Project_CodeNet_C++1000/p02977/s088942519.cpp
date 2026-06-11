// only miss the sun when it starts to snow

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

#define f(a,b) cout<<a<<" "<<b<<"\n"

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n; cin>>n;

    if( (n&(-n)) == n ) return cout<<"No\n",0;
    cout<<"Yes\n";

    if(n&1){
	f(1+n,3);
	for(int i=2;i<n;i+=2)
	    f(1,i), f(i,i+1), f(1,i+1+n), f(i+1+n, i+n);
    }
    else{
	int tw=1<<(31-__builtin_clz(n));

	f(1,tw+1);
	f(tw+1,tw);
	f(tw,tw+2);
	f(tw,1+n);
	f(tw+1,3);
	f(1+n,tw+1+n);
	f(tw,2);
	f(2,tw+2+n);
	f(tw+2+n,tw+n);
	f(tw+n,2+n);
	f(2+n,3+n);

	for(int i=4;i<tw;i+=2)
	    f(1,i), f(i,i+1), f(1,i+1+n), f(i+1+n, i+n);
	for(int i=tw+3;i<n;i+=2){
	    int x= i ^ (i+1);
	    f(x,i), f(i,i+1), f(x,i+1+n), f(i+1+n, i+n);
	}
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
