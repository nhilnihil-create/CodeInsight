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
ll n, k;
ld arr[nax], pref[nax], maks=0;

int main(void){
	IOS
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		if(i==0){
			pref[i]=(arr[i]+1)/2;
		}
		else pref[i]=pref[i-1]+((arr[i]+1)/2);
	}
	for(int i=0;i+k-1<n;i++){
		ld ans=0;
		ans=pref[i+k-1]-pref[i-1];
		maks=max(maks, ans);
	}
	cout << setprecision(10) << fixed;
	cout << maks << '\n';
}
