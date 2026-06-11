#include <iostream>
using namespace std;

int main(void) {
    int a, b, c, d, p, q, r, s;
    cin >> a >> b >> c >> d;
    cin >> p >> q >> r >> s;

    int sum1 = a + b + c + d;
    int sum2 = p + q + r + s;
    
    if (sum1 > sum2)
		cout << sum1 << endl;
	else
		cout << sum2 << endl;

    return 0;
}