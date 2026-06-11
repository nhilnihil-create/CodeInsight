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
ll power( ll a, ll n, ll m){
  ll ans = 1;
  while(n){
  if(n&1)
  {
  ans *= a;
  ans%=m;
  }
  a*=a;
  n/=2;
  }
  return ans ;
} 


template < class T > using oset = tree< T , null_type, less  < T  > , rb_tree_tag , tree_order_statistics_node_update > ;


// end of #define 

// define globals ...
const int maxx = 2e5+26;

//write function from here ...







int Main(){



int k ;
cin>>k;

int n ;
cin>>n;

vector <int  > cl( n+1) ;
vector < int > an( n+1);

vector < int > ar(n+1);

for ( int i =0 ; i < n ;i++){
	
	cin>>ar[i];
	
}

int ans = INT_MAX;

cl[0] = ar[0]+ (k-ar[n-1]);


for( int i=1 ; i <n;i++){
	cl[i] = ar[i] - ar[i-1];
	
}

an [n-1] = ar[0]+ (k-ar[n-1]);
for( int i=n-2;i>=0;i--)
an[i] = ar[i+1]-ar[i];

int sn =0 ;
for( int i=0 ; i < n;i+=1)
sn+=an[i];

int mn = INT_MAX;

for(int i=0 ; i < n;i++)
mn = min(mn , sn - an[i]);

int mx = INT_MAX ;
int sx =0 ;
for( int i=0 ; i< n ;i++)
sx+= cl[i];

for( int i  =0 ; i < n;i++){
	mx = max(mx, sx - cl[i]);
}

cout<<min(mx, mn)<<endl;


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
