#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	int m = 0;
	int k,n,a;
	cin >> k >> n >> a;
	int pa = a;
	for(int i = 1; i<n;i++){
		int an;
		cin >> an;
		if(m < (an-pa)) m = (an-pa);
		pa = an;
	}
	int l = (k-pa) + a;
	if(l > m) m = l;
	cout << k - m << endl;
}
