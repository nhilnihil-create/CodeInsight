#include <iostream>
using namespace std;
int main(void){
	long n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long ans = 0;
    for (int i = 1; i <= n; i++){
		 ans += i * (n - i + 1);
	}
    for (long i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        ans -= x * (n - y + 1);
    }
    cout << ans << endl;
}
