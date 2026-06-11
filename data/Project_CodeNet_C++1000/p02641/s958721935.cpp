#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,x;
	bool a[100000];
	cin >> x >> n;
	while(n--){
		ll z;
		cin >> z;
		a[z]=1;
	}
	ll jwb=-1e9;
	for(int i=-10000; i<=10000; i++){
		if(abs(i-x)<abs(jwb-x) && !a[i]){
			jwb=i;
		}
	}
	cout << jwb << endl;
}