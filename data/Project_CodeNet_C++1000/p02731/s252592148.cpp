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
    long double l;
    cin>>l;
    long double x=l/3;
    cout << fixed << setprecision(10) << x*x*x <<"\n";
	return 0;
}