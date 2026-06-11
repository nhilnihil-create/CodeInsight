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
ll n;
unordered_map<ll, ll>mep;

int main(){
	IOS
	cin >> n;
	ll arr[n+5];
	for(ll i=0;i<n;i++){
		cin >> arr[i];
		mep[arr[i]]++;
	}
	ll total=0;
	for(auto i:mep){
		total+=(i.second*(i.second-1))/2;
	}
	for(ll i=0;i<n;i++){
		cout << total-(mep[arr[i]]*(mep[arr[i]]-1))/2+((mep[arr[i]]-1)*(mep[arr[i]]-2))/2 << '\n';
	}
}