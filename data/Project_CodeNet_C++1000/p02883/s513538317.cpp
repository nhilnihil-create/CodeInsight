#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;


void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

long long int func(vector<ll> &a,vector<ll> &f,ll mid){
	ll n = a.size();
	vector<ll> cost(n);
	ll res = 0;
	rep(i, n) cost[i] = a[i] * f[i];
	rep(i,n){
		if(cost[i] > mid){
			res += (cost[i] - mid + f[i] - 1) / f[i];
		}
	}
	return res;
}

int main() {
	long long int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> f(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	sort(all(a));
	sort(all(f));
	reverse(all(f));

	ll l = -1, r = 1e18;
	while(l+1<r){
		ll mid = (l + r) / 2;
		if (func(a,f,mid) > k)
			l = mid;
		else
			r = mid;

	}
	cout << r << endl;

	return 0;
}