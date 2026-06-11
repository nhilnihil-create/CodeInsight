#include <bits/stdc++.h>
using namespace std;
#define int long long int
main() {
	int n;
	cin>>n;
	vector<int>s;
	vector<int>b;
	for(int i=0; i<n; i++){
		int a1, b1;
		cin>>a1>>b1;
		if(n%2==0){
			s.push_back(2*a1);
			b.push_back(2*b1);
		}
		else{
			s.push_back(a1);
			b.push_back(b1);
		}
	}
	sort(s.begin(), s.end());
	sort(b.begin(), b.end());
	if(n%2==1){
		cout<<b[n/2]-s[n/2]+1;
		return 0;
	}
	else{
		cout<<((b[n/2]+b[(n/2)-1])/2)-((s[n/2]+s[(n/2)-1])/2)+1;
		return 0;
	}
	return 0;
}