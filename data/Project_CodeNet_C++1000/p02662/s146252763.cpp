#include<bits/stdc++.h>
using namespace std ;
const long long mod = 998244353 ;
const int N  = 3005 ;
long long int a[N][N] ;
int main() {
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt" , "r" , stdin) ;
	//for writing output to output.txt
	freopen("output.txt" , "w" , stdout) ;
#endif
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	int s ;
	vector<int>::size_type n ;
	cin >> n >> s  ;
	vector<int> arr ;
	for (decltype(n) i  = 0 ; i < n ; ++i) {
		int temp ;
		cin >> temp ;
		arr.push_back(temp) ;
	}
	a[0][0] = 1 ;
	for (decltype(n) i = 0 ; i < n ; ++i) {
		for (int j = 0 ; j <= s ; ++j) {
			a[i + 1][j] += 2 * a[i][j] ;
			a[i + 1][j] %= mod ;
			if (j + arr[i] <= s) {
				a[i + 1][j + arr[i]] += a[i][j] ;
				a[i + 1][j + arr[i]] %= mod ;

			}

		}
	}
	cout << a[n][s] << endl ;


}