#include <bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(), arr.end() 
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll sums=0, n;

int main(){
	IOS
	cin >> n;
	int arr[n+5];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sums+=arr[i]*arr[j];
		}
	}
	cout << sums << '\n';
}
