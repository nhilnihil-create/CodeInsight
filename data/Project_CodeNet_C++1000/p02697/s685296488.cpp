#include <bits/stdc++.h>

using namespace std;

int main(int, char**) {
        long long n, m;
        cin >> n >> m;
        long long m_max = (n - 1) / 2;
        int dif_e, dif_o;
        bool odd;
        if (m_max%2==0) {
                odd = false;
                dif_e = m_max;
                dif_o = m_max - 1;
        } else {
                odd = true;
                dif_o = m_max;
                dif_e = m_max - 1;
        }
        for (long long i=0; i<m; i++) {
                long long a, b;
                int j = i/2;
                if (!odd) {
                        a = j + 1;
                        b = a + dif_e - 2 * j;
                } else {
                        a = dif_e + 2 + j;
                        b = a + dif_o - 2 * j;
                }
                cout << a << " " << b << endl;
                odd = !odd;
        }
        return 0;
}
