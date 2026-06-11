#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dob double
int main(){
	int n,a;
	cin>>n>>a;
	int ans = max(n-2*a, 0);
	cout<<ans;
	return 0;
}
