#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
using namespace std;
int num[100005];
int main(){
	int n,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum = -sum + num[i];
	}
	for (int i = 0; i < n; i++) {
		cout << sum<<' ';
		sum = 2 * (num[i] - sum / 2);
	}
	return 0;
}