	#include<bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp> // Common file
	#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
	#include <ext/pb_ds/detail/standard_policies.hpp>


	/* 
	*    coder :: ATUL_PANDEY_2608
	*        >>> INDIA <<<
	*/
	using namespace std;
	using namespace __gnu_pbds;

	// #define  part ..
	#define pb(a) push_back(a)
	#define all(a) a.begin(),a.end() 
	#define mod 1000000007
	//#define maxx 200006
	#define ll long long 
	#define quick    ios_base::sync_with_stdio(NULL),cin.tie(0);
	#define listll vector< long long > 
	#define listi vector< int> 
	#define pii   pair<int , int> 
	#define pll pair<long long , long long > 
	#define minheap priority_queue<long long , vector< long long >, greater<long long > >
	#define rep(i,a,b) for(int i=a;i<b;i++)
	ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


	template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


	// end of #define 

	// define globals ...
	const int maxx = 1e6+26;

	//write function from here ...

	ll ft[maxx] ;

	int n;

	void update( int  i , int val){
		
		for(  ++i ; i<=n;i+=(i&-i) ){
			
			ft[i]+=val;		
		}
		
	}

	ll qry( int i ){
		ll ans  =0 ; 
		for ( ; i ; i-=( i&-i)){
			
			ans += ft[i];
		}
		
		return ans ;
		
		
	}







	int Main(){
	   
	   
	   
	   cin>>n;
	   int q;
	   cin>>q;
	   
	   memset( ft, 0 , sizeof(ft));
	   
	   vector < ll > arr(n);
	   for( int i =0 ; i < n;i++){
		   cin>>arr[i];
		   update( i  , arr[i]);
	   
	   }
	   
	   while(q--){
		   int a;
		   cin>>a;
		   
		   if(a== 1){
			   
			   ll l,r;
			   cin>>l>>r;
			   ll val = qry(r) - qry( l );
			   cout<<val<<endl;
			   
		   }
		   else {
			   
			   ll p ,x;
			   cin>>p>>x;
			   //update( p ,arr[p]);
			   update( p ,x);
			   arr[p]+= x;
			   
			   
			   
		   }
		   
		   
		   
	   }




	return 0;

	}






	int main(){
	 quick;
	int t =1; 
	//cin>>t;
	while(t-- )
	 Main();

	 return 0;


	}
