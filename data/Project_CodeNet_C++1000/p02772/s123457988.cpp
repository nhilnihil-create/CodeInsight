#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N; cin >> N;
        vector<ll> A(N, 0);
        for (int i = 0; i < N; ++i) {
                ll tmp;
                cin >> tmp;
                A[i] = tmp;
        }

        for (int i = 0; i < N; ++i) {

                if (A[i] % 2 == 0) {
                        if (A[i] % 3 == 0 || A[i] % 5 == 0) {

                        }
                        else {
                                cout << "DENIED" << endl;
                                exit(0);
                        }
                }
        }
        cout << "APPROVED" << endl;


}
