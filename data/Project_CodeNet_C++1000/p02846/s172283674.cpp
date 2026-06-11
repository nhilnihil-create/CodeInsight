#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

llint t1, t2;
llint a1, a2, b1, b2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	if(a1 < b1) swap(a1, b1), swap(a2, b2);
	
	llint d1 = a1-b1, d2 = a2-b2;
	llint dif = d1*t1+d2*t2;
	
	if(dif == 0){
		cout << "infinity" << endl;
		return 0;
	}
	if(dif > 0){
		cout << 0 << endl;
		return 0;
	}
	
	dif *= -1;
	
	llint top = d1*t1;
	llint ans = (top+dif-1)/dif*2;
	if(top % dif == 0) ans++;
	cout << ans-1 << endl;
	
	return 0;
}