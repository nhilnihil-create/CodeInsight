#include<bits/stdc++.h>
using namespace std;
#define int long long 

main(){
	int x,k,d,val; cin>>x>>k>>d;
	
	if(x == 0){
		if(k%2) cout<<d;
		else cout<<x;
	}
	else if(x > 0){
		if(k > (x+d-1)/d){
			val = x - ((x+d-1)/d) * d;
			k -= (x+d-1)/d;
			if(k%2) cout<<abs(val+d);
			else cout<<abs(val);
		}
		else{
			cout<<abs(x - d*k);
		}
	}
	else{
		if(k > (abs(x)+d-1)/d){
			val = x + ((abs(x)+d-1)/d) * d;
			k -= (abs(x)+d-1)/d;
			if(k%2) cout<<abs(val-d);
			else cout<<abs(val);
		}
		else{
			cout<<abs(x + d*k);
		}
	}
}