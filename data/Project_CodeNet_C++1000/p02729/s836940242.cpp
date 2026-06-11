#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
int n, m;

int main(){
	IOS
	vector<int>arr;
	cin >> n >> m;
	while(n--){
		arr.push_back(2);
	}
	while(m--){
		arr.push_back(1);
	}
	ll ans=0;
	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
			if((arr[i]+arr[j])%2==0){
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
}