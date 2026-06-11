#include <bits/stdc++.h>                
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n,a,b;
    cin>>n>>a>>b;
    long long int ans=(n/(a+b))*a;
    n%=a+b;
    ans+=min(a,n);
    cout<<ans<<"\n";
	return 0;
}