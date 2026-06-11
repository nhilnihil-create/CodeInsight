#include<bits/stdc++.h>
#include<vector>
#define inf 10000000000000
#define ll unsigned long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])
#define mod 1000000007;
 
using namespace std;
// lower_bound
// it returns pos of the elmnt which is not less then the query elmnt
int main() {
	int n; cin >> n;
	vector<int> arr(n,0);

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	int sum = 1e9;
	for(int i = 0; i <= 100; i++){
		int x = 0;
		for(int j = 0; j < n; j++){
			x += ( (arr[j] - i) * (arr[j] - i) );
		}
		sum = min(sum, x);
	}
	cout << sum << endl;
}



