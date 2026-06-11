#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>;

int main() {
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	int k = 60 * h + m;
	int mm = 12 * 60;
	double angh = 360.0 * double(k) / double(mm);
	double angm = 360.0 * double(m) / double(60);
	double ang = abs(angh - angm);
	//cout << ang;
	double pi = 3.1415926535;
	double cosa=cos(ang/180.0*pi);
	double ans = sqrt(a * a + b * b - 2 * a * b * cosa);
	cout << setprecision(15)<<ans;
	
	return 0;
}