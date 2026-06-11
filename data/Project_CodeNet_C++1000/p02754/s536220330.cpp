#include <iostream>
#include<algorithm>
using namespace std;
int main(){
	long long int n, a, b,ans;
	cin >> n >> a >> b;
	ans = n / (a + b)*a;
	ans += min(n % (a + b), a);
	cout << ans;
}