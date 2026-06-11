#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
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
const ll nax = 1e5+5;
int n, arr[nax];

int main(){
	IOS
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	sort(arr+1, arr+n+1);
	if(arr[n/2]==arr[n/2+1]){
		cout << 0 << '\n'; return 0;
	}
	cout << abs(arr[n/2]-arr[n/2+1]) << '\n';
}
