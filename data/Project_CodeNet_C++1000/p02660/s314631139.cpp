#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;
vector<int> R(41, 0);
int search(int s){
	int r = 41;
	int l = 0;
	while(l+1 < r){
		int m = (l+r)/2;
		if(R[m]>s){
			r = m;
		}else if(R[m]<s){
			l = m;
		}else{
			l = m;
			break;
		}
	}
	return l;
}

int main(){
	ll N;
	cin >> N;
	vector<pair<ll, int>> a(0);
	ll n = N;
	for(ll i = 2; i*i<=n; i++){
		if(N%i == 0){
			int count = 0;
			while(N%i == 0){
				count ++;
				N/=i;
			}
			a.push_back(make_pair(i, count));
		}
	}
	if(N != 1) a.push_back(make_pair(N, 1));
	for(int i = 1; i< 41; i++){
		R[i] = R[i-1]+i;
	}
	ll ans = 0;
	for(int i = 0; i < a.size(); i++){
		int s = a[i].second;
		if(s == 1 || s == 2) ans++;
		else if(s == 3) ans+= 2;
		else{
			ans += search(s);
		}
	}
	cout << ans << endl;
}
