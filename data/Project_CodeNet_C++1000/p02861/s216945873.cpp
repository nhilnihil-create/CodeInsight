#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int N;
    cin >> N;
    vector<int> x_vec(N), y_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> x_vec.at(i) >> y_vec.at(i);
    double sum_dist = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dx = x_vec.at(j) - x_vec.at(i);
            int dy = y_vec.at(j) - y_vec.at(i);
            sum_dist += hypot(dx, dy);
        }
    }
    cout << setprecision(10) << 2 * sum_dist / N << endl;
}
