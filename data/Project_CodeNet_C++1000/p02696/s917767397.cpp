#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a,b,n;
	cin>>a>>b>>n;
	cout<<a*min(b-1,n)/b;
	return 0;
}