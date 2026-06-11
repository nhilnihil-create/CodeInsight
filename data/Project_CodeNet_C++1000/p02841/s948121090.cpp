#include <iostream>
using namespace std;

int main() {
	int m1,m2,d1,d2;cin >> m1>>d1;
	cin >> m2>>d2;
	int ans;
	if(m1<m2){
		ans =1;
	} else {
		ans =0;
	}
	cout << ans << endl;
	return 0;
}