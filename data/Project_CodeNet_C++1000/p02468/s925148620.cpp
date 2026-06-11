#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MOD 1000000007

int main() {
        int i, t, k, r;
        long long m, m1;
        long long mm[33];
        long n, bt = 1, m2 = 1;

        cin >> m >> n;
        mm[0] = m1 = m;
        for (i = 1; i < 33; i++) {
                m1 = m1 * m1;
                m1 = m1 % MOD;
                mm[i] = m1;
        }
        for (i = 0; i < 33; i++) {
                if (n & bt) {
                        m2 = m2 * mm[i];
                        m2 = m2 % MOD;
//                      cout << i << endl;
                }
                bt <<= 1;
        }

        cout << m2 << endl;

        return 0;
}

