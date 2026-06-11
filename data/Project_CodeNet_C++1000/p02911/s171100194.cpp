#include<iostream>
#define ll long long
using namespace std;

ll a[1000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,k,q;
	cin >> n >> k >> q;
	for(int i=0; i<n; i++){
		a[i]=i;
	}
	ll freq[n]={0};
	for(int i=0; i<q; i++){
		ll ans;
		cin >> ans;
		freq[ans-1]++;
	}
	for(int i=0; i<n; i++){
		if(k-q+freq[i]>0) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
	return 0;
}