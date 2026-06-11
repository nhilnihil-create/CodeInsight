#include <bits/stdc++.h>
using namespace std;


//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;

	//typedef tree<
			//int,
			//null_type,
			//less<int>,
			//rb_tree_tag,
			//tree_order_statistics_node_update>
	//ordered_set;
	

//#define REP(i,m) for(int i=0;i<(m);++i)
//struct dsu{
	//static const int MAXN=105;
	//int par[MAXN];
	//int size[MAXN];
	//void init(){
		//memset(par,-1,sizeof(par));
		//REP(i,MAXN) size[i]=1;
	//}
	//int root(int a){
		//if(par[a]==-1) return a;
		//return par[a]=root(par[a]);
	//}
	//void unite(int a,int b){
		//a=root(a);b=root(b);
		//if(a==b) return;
		//if(size[a]<size[b]) swap(a,b);
 
		//par[b]=a;
		//size[a]+=size[b];
	//}
	//bool same(int a,int b){
		//return root(a)==root(b);
	//}
//};	

#define ll long long 

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll n;cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+= (i+1)*(n-i);
	}
	for(int i=0;i<n-1;i++){
		ll a,b;cin>>a>>b;
		ans-= (min(a,b)*(n-max(a,b) +1));
	}
	cout<<ans<<endl;
	return 0;
	
}
