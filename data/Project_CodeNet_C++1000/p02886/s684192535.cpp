#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std; 
#define ll long long
#define pb push_back
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define mp make_pair
#define endl "\n"
#define N (ll)2e5+10 




int main(){
    
    ios::sync_with_stdio(0);
    
    int n ;
    cin >> n ;
    int d[n] , i , j;
    for(i=0 ; i<n ; i++){
    	cin >> d[i] ;
    }
    int ans = 0 ;
    for(i=0  ; i<n ; i++){
    	for(j=i+1 ; j<n ; j++){
    		ans += d[i]*d[j] ;
    	}
    }
    cout << ans ;

    return 0 ;
 }