#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
	long double a, b, c;
	cin >> a >> b >> c;
	long double d = sqrt(a*b)*2;
	if(c > a+b+d) cout << "Yes" << endl;
	else cout << "No" << endl;
}
