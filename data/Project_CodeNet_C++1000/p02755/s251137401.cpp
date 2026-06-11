#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll A, B; cin >> A >> B;


        for (int i = 1; i <= 1250; ++i) {

                ll eight = i / 100.0 * 8.0;
                ll ten = i / 100.0 * 10.0;
                if (eight == A && ten == B) {
                        cout << i << endl;
                        exit(0);
                }

        }
        cout << -1 << endl;


}
