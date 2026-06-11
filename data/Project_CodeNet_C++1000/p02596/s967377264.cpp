#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int mod; cin >> mod;
    	int rem = 0;
    	set<int> all;
    	for(int i = 1; ; i++)
    	{
    		rem = ((rem*10) % mod + 7) % mod;
    		if(rem == 0){
    			cout << i ;
    			return 0;
    		}
    		if(all.find(rem) == all.end())
    			all.insert(rem);
    		else{
    			cout << -1;
    			return 0;
    		}
    	}
    }    
}