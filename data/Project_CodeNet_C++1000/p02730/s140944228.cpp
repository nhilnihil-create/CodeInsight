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
    bool flag=true;
    for (int i=0;i<s.size()/2;i++)
        if(s[i]!=s[s.size()-1-i])
            flag=false;
    int l=0;
    int r=(s.size()-1)/2-1;
    while (l<r){
        if(s[l]!=s[r])
            flag=false;
        l++;
        r--;
    }
    l=(s.size()+3)/2-1;
    r=s.size()-1;
    while (l<r){
        if(s[l]!=s[r])
            flag=false;
        l++;
        r--;
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
	return 0;
}