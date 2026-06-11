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
    string s;
    cin>>s;
    int q;
    cin>>q;
    int cnt=0;
    while (q--){
        int t;
        cin>>t;
        if(t==1)
            cnt++;
        else{
            int f;
            char c;
            cin>>f>>c;
            if(cnt%2==f%2) s+=c; 
            else s=c+s;
        }    
    }
    if(cnt%2) reverse(s.begin(),s.end());
    cout<<s<<"\n";
	return 0;
}