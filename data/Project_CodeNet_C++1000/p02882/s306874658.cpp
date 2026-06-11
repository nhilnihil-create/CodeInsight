#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;
using vd = vector<double>;
int main(){
	double a, b, x;
	cin >> a >> b >> x;
	double i = 2*x / (a*b);
	double PI = 3.14159265359;
	double ans;
	if(i > a){
		double i = 2*x/(a*a) - b;
		double j = b - i;
		double c = a*a / (a*a + j * j);
		ans = acos(sqrt(c))*180/PI;
	}else{
		double c = i*i / (i*i + b* b);
		ans = acos(sqrt(c))*180/PI;
	}
	cout << fixed << setprecision(15) << ans << endl;
}
