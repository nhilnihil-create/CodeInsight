#include <iostream>

using namespace std;

int main(){
	long long n,a,b;
	cin >> n >> a >> b;
	
	long long count = n / (a+b);
	long long ans = count * a;
	
	long long res = n - (count*(a+b));
	if(res > a){
		ans += a;
	}
	else if(res < a){
		ans += res;
	}
	
	cout << ans << endl;
	
	
}