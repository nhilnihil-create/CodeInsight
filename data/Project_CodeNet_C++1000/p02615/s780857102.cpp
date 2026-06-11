# include <bits/stdc++.h>
# define ll long long int
# define ld long double
# define pb push_back
# define mp make_pair
# define mod 1000000007
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
// online submission
	#endif
	IOS
	int n;
	cin >> n;
	ll arr[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());
	ll sum = arr[0];
	for(int i = 1; i < n; i++){
		if((2*i) < n)
			sum += arr[i];
		if(2*i + 1 < n)
			sum += arr[i];
	}
	cout << sum;
	return 0;
}