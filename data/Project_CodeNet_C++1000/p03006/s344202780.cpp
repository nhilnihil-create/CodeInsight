#include <bits/stdc++.h>
using namespace std;

int main()
{
        int N;
        cin >> N;
        int x[N];
        int y[N];
        for (int i = 0; i < N; ++i) {
                cin >> x[i] >> y[i];
        }

        if (N == 1) {
                cout << 1 << endl;
                exit(0);
        }

        long long ans = -1;
        for (int i = 0; i < N; ++i) {

                for (int j = 0; j < N; ++j) {

                        if (i == j) continue;

                        long long p = x[j] - x[i];
                        long long q = y[j] - y[i];
                        long long cnt = 0;
                        for (int ii = 0; ii < N; ++ii) {

                                for (int jj = 0; jj < N; ++jj) {

                                        if (ii == jj) continue;

                                        long long pp = x[jj] - x[ii];
                                        long long qq = y[jj] - y[ii];

                                        if (p == pp && q == qq) {

                                                cnt++;
                                        }
                                }
                        }

                        if (ans == -1) {
                                ans = N - cnt;
                        }
                        else {
                                if (ans > N - cnt) {
                                        ans = N - cnt;
                                }
                        }

                }
        }
        cout << ans << endl;

}
