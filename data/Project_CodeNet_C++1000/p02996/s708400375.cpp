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
const ll nax = 0;
ll n;

struct struk{
		ll waktu, batas;
	};

bool cmp(struk s1, struk s2){
		if(s1.batas!=s2.batas){
			return s1.batas<s2.batas;
		}
		else{
			return s1.waktu<s2.waktu;
		}
	}

int main(){
	IOS
	cin >> n;
	vector<struk>v;
	for(int i=0;i<n;i++){
		ll a, b;
		cin >> a >> b;
		v.pb({a, b});
	}
	sort(v.begin(), v.end(), cmp);
	ll temp=0;
	for(int i=0;i<n;i++){
		temp+=v[i].waktu;
		if(temp>v[i].batas){
			cout << "No" << '\n';
			return 0; 
		}
	}
	cout << "Yes" << '\n';
}
