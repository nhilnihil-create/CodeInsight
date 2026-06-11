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
const int maxx = 2e5+26;

//write function from here ...







int Main(){

int n,m;
cin>>n>>m;

map< int , char > mp ;
bool flag = 0 ;
array < int, 10 > arr;
for(int i =0 ; i < m;i++){
	
	int s,c;
	cin>>s>>c;
	s--;
	if( !mp.count(s))
	mp[s] = (char)c+48;
	else
	{
		if ((mp[s])!= (char)48+c) 
		flag  =1;
		
	}
	
	arr[s] = c;
	
	
}
ll ans =0 ; 


if(flag == 1)
{
	cout<<-1<<endl;
	return  0 ;
}


string ss = string( n , '*');
for(int i=0 ; i <n;i++){
	
	    if(mp.count( i ))
		ss[i] =  (char)(48+arr[i]);
	
}

if(ss.length() > 1){
	
	if(ss[0] == '0')
	{
		cout<<-1<<endl;
		return  0 ;
	}
	else if( ss[0]=='*')
	ss[0] = '1';
}

for(int i =0 ; i < n ;i++)
if(ss[i] == '*') ss[i] = '0';




//if(ss.length() > 1 && ss[0]=='0')
//{
	//cout<<-1<<endl;
	//return  0; 
//}

cout<<ss<<endl;



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
