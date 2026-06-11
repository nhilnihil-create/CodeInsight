#include <iostream>

using namespace std;

int main(void) {
        long long x, k, d;

        cin >> x >> k >> d;

        x = abs(x);

        if (k < x / d) {
                for (long long i = k; i > 0; i--) {
                        x -= d;
                }
                cout << x << endl;
        } else {
                long long div = x / d;
                if (div == k) {
                        cout << abs(x-div*d) << endl;
                } else {
                        if ((k - div) % 2)
                                div++;
                        cout << abs(x-div*d) << endl;
                }
        }

        return 0;
}