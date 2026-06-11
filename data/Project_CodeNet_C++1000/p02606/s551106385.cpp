#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define black_tree tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define pair_black_tree tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update>
#define gp __gnu_pbds
#define INF 1000000000
#define MOD 1000000007
#define MAX 200001
#define endl '\n'
#define ll long long
#define ld long double
#define lli long long int
#define ull unsigned long long
#define ulli unsigned long long int
#define pb push_back
#define pf push_front
#define ook order_of_key
#define fbo find_by_order
#define np next_permutation
#define mp make_pair
#define eb emplace_back 
#define mae max_element
#define mie min_element
#define lb lower_bound 
#define ub upper_bound
#define bs binary_search
#define ff first
#define ss second
using namespace std;
using namespace gp;
ll l,r,d,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>l>>r>>d;
	for(int i=1;i<=(r+1)/d;i++){
		if(i*d>=l && i*d<=r){
			ans++;
		}
	}
	cout<<ans;
}