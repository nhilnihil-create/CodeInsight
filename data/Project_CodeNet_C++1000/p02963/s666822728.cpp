#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int s;
	cin>>s;
	if(s==1000000000000000000){
		cout<<0<<" "<<0<<" "<<0<<" "<<1000000000<<" "<<1000000000<<" "<<0;
		return 0;
	}
	cout<<1000000000<<" "<<(1+(s/1000000000))<<" "<<0<<" "<<(s/1000000000)<<" "<<(s%1000000000)<<" "<<0;
	
	return 0;
}