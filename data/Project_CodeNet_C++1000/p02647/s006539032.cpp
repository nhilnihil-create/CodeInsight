/*input
5 2
1 0 0 1 0
*/
/*

**************************
*						 *
* AUTHOR :: knight_coder *
*						 *
**************************

*/
#include<bits/stdc++.h>
#define lld          long long int
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<lld,lld>
#define msi         map<string,lld>
#define mis         map<lld, string>
#define mpi         map<pair<lld ,lld >,lld >
#define pii         pair<lld,lld>
#define vi          vector<lld>
#define vpi 		vector<pii>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (lld)x.size()
#define hell        1000000007
#define rrep(i,m,n)	for(lld i=m;i>=n;i--)
#define rep(i,m,n)	for(lld i=m;i<n;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
#define pr(x) 		cout<< x << " ";
#define pre(x)		cout<< x << endl ;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
//change null_type to get ordered_map
#define N  200005
lld a[N],b[N];
void solve()
{	
	lld n,k;
	cin >> n >> k;
	rep(i,0,n){
		cin >> a[i];
	}
	while(k>0){
		rep(i,0,n){
			lld t=min(n-1,a[i]+i);
			lld r=max(0LL,i-a[i]);
			b[r]++,b[t+1]--;
		}	
		rep(i,1,n){
			b[i]+=b[i-1];
		}
		bool f=1;
		rep(i,0,n){
			a[i]=b[i];
			if(a[i]!=n){
				f=0;
			}
			b[i]=0;
		}
		b[n]=0;
		k--;
		if(f){
			break;
		}
	}
	rep(i,0,n){
		cout << a[i] << ' ';
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1;
	//cin>>tests;
	while(tests--)
	{
		solve();
	}
}
