#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	int ans = 0;
	ll s = 100;
	while (s < n){
		ans++;
		s = s + s/(100);
	}
	cout<<ans;
}