    //programking2_b.cpp
    //Sun Dec  8 11:18:32 2019
     
    #include <iostream>
    #include <string>
    #include <queue>
    #include <map>
    #include <unordered_map>
    #include <vector>
    #include <algorithm>
    #include <math.h>
    #include <set>
    #define INTINF 2147483647
    #define LLINF 9223372036854775807
    using namespace std;
    using ll=long long;
    typedef pair<int,int> P;
     
    int main(){
    	int n;
    	cin >> n;
     
    	ll node[n];
    	ll d[n];
    	fill(node,node+n,0);
    	ll maxnode = 0;
    	for (int i=0;i<n;i++){
    		cin >> d[i];
    		node[d[i]]++;
    		maxnode = max(maxnode,d[i]);
    	}
     
    	if (node[0]!=1 || d[0]!=0){
    		cout << 0 << endl;
    		return 0;
    	}
     
    	ll ans = 1;
    	for (int i=1;i<=maxnode;i++){
    		ll temp = node[i];
    		while (temp){
    			ans = ans * node[i-1] % 998244353;
    			temp--;
    		}
    	}
     
    	cout << ans << endl;
    //	printf("%.4f\n",ans);
    }