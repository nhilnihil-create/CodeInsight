#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(){
	ll h,k;
	cin>>h>>k;
	ll sum=0;
	vector<ll> a(h);
	for(ll i=0;i<h;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(ll i=0;i<h-k;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
}