#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,cnt=0, s = 100;
	cin>>n;
	while (s < n){
		cnt++;
		s = s + s/(100);
	}
	cout<<cnt;
}
