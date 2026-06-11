#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int

main() {
	int n, a, b;
	cin>>n>>a>>b;
	if((b-a)%2==0){
		cout<<(b-a)/2;
		return 0;
	}
	else{
		int ans1;
		int ans2;
		int cnt=a;
		int pos=b-a;
		ans1=cnt+((b-a-1)/2);
		cnt=n-b+1;
		pos=a+cnt;
		ans2=cnt+((n-pos)/2);
	
		cout<<min(ans1, ans2);
	}
	return 0;
}