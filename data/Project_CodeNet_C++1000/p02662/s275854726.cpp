//                                               KEEP GRINDING
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>   new_data_set;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

#define int long long
#define ld long double
#define MOD 1000000007
#define mod 998244353
#define precise(i) fixed << setprecision(10) << i
#define f(i,a,b) for(int i=a;i<b;++i)

#define endl '\n'
#define debug cout<<"\n========================================\n"<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl;
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl;
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl;

#define all(a) a.begin(),a.end()
#define show(a) for(auto xyz:a)cout<<xyz<<" ";cout<<endl;
#define PQ priority_queue
#define mx(a) *max_element(a)
#define mn(a) *min_element(a) 
#define LB lower_bound  //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS >= OUR VALUE 
#define UB upper_bound  //THIS GIVES THE ITR TO THE ELEMENT IN RANGE [SI,EI) THAT IS > OUR VALUE 

#define fr first
#define sc second

#define MAXN 500000
#define INF 9223372036854775807
int power(int x, int y, int m=mod) 
{ 
    if (y == 0) 
        return 1; 
    int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}  
signed main(){
    fastio
    int N , S ;
    cin >> N >> S ;
    vector< int > a(N);
    f(i,0,N){
    	cin >> a[i] ;
	}
	int MI=power(2,mod-2);
	int dp[N+1][S+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=power(2,N);
	f(i,0,N){
		f(j,0,S+1){
			dp[i+1][j]=( dp[i+1][j] + dp[i][j] )%mod;
			if( j + a[i] <= S)
			    dp[i+1][j+a[i]]=( dp[i+1][j+a[i]] + dp[i][j]*MI )%mod;
		}
	}
	cout << dp[N][S] ;
	
}