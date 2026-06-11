#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll k;
int n;
bool check(ll mid,vector<ll> a, vector<ll> b){
	ll sum=0;
	for(int i=0;i<n;i++){
		sum += max(a[i] - mid/b[i],0ll);
	}
	if(sum > k ) return 0;
	else return 1;
}
int main(){
	cout << fixed << setprecision(10);
	cin >> n >> k;
	vector<ll> a(n),f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];
	sort(a.begin(),a.end());
	sort(f.begin(),f.end());
	reverse(f.begin(),f.end());
	ll left = -1, right = (ll)1e13;
	ll mid;
	ll cnt = 0;
	while(left+1<right){
		mid = (left+right)/2;
		if(check(mid,a,f)){
			right = mid;
		}
		else{
			left = mid;
		}
		cnt++;
	}
	cout << right << endl;
	return 0;
}