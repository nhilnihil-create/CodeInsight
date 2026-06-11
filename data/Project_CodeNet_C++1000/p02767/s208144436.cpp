#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int n;
	cin >> n;
	v1 a(n);
	int s = 0;
	rep(i, n){
		int x;
		cin >> x;
		a[i] = x;
		s += x;
	}
	int p1 = s/n;
	int p2 = s/n + 1;
	int s1 = 0;
	int s2 = 0;
	rep(i, n){
		s1 += (p1-a[i])*(p1-a[i]);
		s2 += (p2-a[i])*(p2-a[i]);
	}
	cout << min(s1, s2) << endl;
}
