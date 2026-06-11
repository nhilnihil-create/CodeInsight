#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 1;

int32_t main(){
 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
 	int n ;
 	cin >> n;
 	int a[n + 1] , b[n + 1] , c[n + 1];

 	for(int i = 1 ; i <= n ; i++) cin >> a[i];
 	for(int i = 1 ; i <= n ; i++) cin >> b[i];
 	for(int i = 1 ; i < n ; i++) cin >> c[i];

 	int sum = b[a[1]];

 	for(int i = 2 ; i <= n ; i++){
 		sum += b[a[i]];
 		if(a[i] - a[i - 1] == 1) sum += c[a[i - 1]];
 	}
 	cout << sum << endl;

 return 0;
}