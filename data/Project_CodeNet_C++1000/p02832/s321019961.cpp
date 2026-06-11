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
bool yah=0;
int n, l[200005], ans=0;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> l[i];
	}
	int curr=1;
	for(int i=0;i<n;i++){
		if(l[i]!=curr){
			ans++;
		}
		else{
			yah=1;
			curr++;
		}
	}
	if(!yah){
		cout << -1 << '\n'; return 0;
	}
	cout << ans << '\n';
}
