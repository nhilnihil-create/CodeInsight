#include <iostream>
#define int long long
using namespace std;

signed main() {
	int n, b, a, box, zan, ans;
	
	cin>>n >>a >>b;
	box = n/(a+b);
	zan = n-box*(a+b);
	
	if(a-zan >= 0){
		ans = a*box+zan;
	}
	else {
		ans = box*a+a;
	}
	cout<<ans;
	return 0;
}