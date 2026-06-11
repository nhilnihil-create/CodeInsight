//                                               KEEP GRINDING
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

#define int long long
#define ld long double
#define precise(i) fixed << setprecision(10) << i
#define f(i,a,b) for(int i=a;i<b;++i)

#define endl '\n'
#define debug cout<<"\n========================================\n";
#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl;

#define PQ priority_queue
#define LB lower_bound  
#define UB upper_bound
#define fr first
#define sc second

#define all(a) (a).begin(),(a).end()
#define allr(a) (a).rbegin(),(a).rend()
#define show(a) {for(auto xyz:a)cout<<xyz<<" ";cout<<endl;}
#define sz(x) (int)(x).size()
const int MOD = 2019 ;
void solve(){
	string s;	cin>>s;		reverse(all(s));
	vector<int> a(sz(s)),rem(MOD,0);
	int ans=0,p=1;
	f(i,0,sz(s)){
		a[i]=( ( p*(s[i]-'0') ) + (i!=0 ? a[i-1] : 0LL) )%MOD;
		p=(p*10)%MOD;
		rem[a[i]]++;
	}
	for(auto i:rem)	ans+=(i*(i-1))/2;
	cout<<ans+rem[0]<<endl;
	
	
	
}
signed main(){
    fastio
    int t=1;
    for(;t--;solve());
}