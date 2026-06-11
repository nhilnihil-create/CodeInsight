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
    int k;
    cin>>k;
    long long int ans=0;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=k;j++)
            for (int l=1;l<=k;l++)
                ans+=__gcd(__gcd(i,j),l);
    cout<<ans<<"\n";            
	return 0;
}