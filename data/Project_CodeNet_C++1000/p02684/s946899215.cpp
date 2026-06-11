#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(val) cerr << "Value " << #val << " : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ld epsilon = 10e-9;
const ll nax = 2e5+5;
ll n, k, arr[nax];	
vector<ll>a, b;

int main(void){
	IOS
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	set<ll>cek;
	ll curr=1;
	while(1){
		if(cek.count(curr)) break;
		cek.insert(curr);
		a.eb(curr);
		curr=arr[curr];
	}
	cek.clear();
	curr=a[a.size()-1];
	while(1){
		if(cek.count(curr)) break;
		cek.insert(curr);
		b.eb(curr);
		curr=arr[curr];
	}
	if(k<=a.size()-1){
		cout << a[k] << '\n';
	}
	else{
		k-=a.size();
		k%=b.size();
		cout << b[(k+1)%b.size()] << '\n';
	}
}
