#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
	int n; cin >> n ;
	int a[n];
	for(int i=0 ; i < n ; i++){
		cin >> a[i];
	}
	ll sum =0;
	for(int i=0 ; i < n ; i++){
		for(int j=i+1 ; j < n ; j++){
			sum+=(a[i]*a[j]);
		}
	}
	cout << sum << endl;
}