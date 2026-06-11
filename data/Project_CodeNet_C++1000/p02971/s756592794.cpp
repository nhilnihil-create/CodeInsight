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
const ll nax = 2e5+5;
ll n, maks=-1, arr[nax], rra[nax];
unordered_map<ll, ll>cnt;

bool cmp(ll s1, ll s2){
		return s1>s2;
	}

int main(){
	IOS
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> rra[i];
		arr[i]=rra[i];
		cnt[rra[i]]++;
	}
	sort(arr+1, arr+n+1, cmp);  
	for(int i=1;i<=n;i++){
		if(rra[i]==arr[1]){
			if(cnt[rra[i]]>1){
				cout << rra[i] << '\n';
			}
			else{
				cout << arr[2] << '\n';
			}
		}
		else{
			cout << arr[1] << '\n';
		}
	}
}
