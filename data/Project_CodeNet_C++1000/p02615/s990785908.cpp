#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,a[200050];
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,greater<ll>());
	ll jwb=0;
	for(int i=2; i<=n; i++){
		jwb+=a[(i+1)/2];
	}
	cout << jwb << endl;
}