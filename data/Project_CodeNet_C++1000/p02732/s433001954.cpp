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
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    map <int,long long int> m;
    for (int i=0;i<n;i++) m[a[i]]++;
    long long int ans=0;
    for (auto i : m) ans+=(i.second*(i.second-1))/2;
    for (int i=0;i<n;i++){
        long long int temp=ans-(m[a[i]]*(m[a[i]]-1))/2;
        temp+=((m[a[i]]-1)*(m[a[i]]-2))/2;
        cout<<temp<<"\n";
    }
	return 0;
}