#include<iostream>
#include<vector>
#include<algorithm>

#define INF 100000

using namespace std;

int main()
{

    while (true) {
        int m, n_min, n_max;
        cin >> m >> n_min >> n_max;
        if (m==0 && n_min ==0 && n_max == 0) {
            return 0;
        }
        vector<int> pv(m);
        for (int i = 0; i < m; i++) {
            cin >> pv[i];
        }
        sort(pv.rbegin(), pv.rend());
        int d_max = -INF;
        int result = n_min;
        for (int n = n_min; n <= n_max; n++) {
            int d = pv[n - 1] - pv[n];
            if (d >= d_max) {
                d_max = d;
                result = n;
            }
        }
        cout << result << endl;
    }
    return 0;
}