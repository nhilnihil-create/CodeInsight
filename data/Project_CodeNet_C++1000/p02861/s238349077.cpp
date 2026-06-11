#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int N;
    cin >> N;
    vector<int> x_vec(N), y_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> x_vec.at(i) >> y_vec.at(i);
    vector<int> route(N, 0);
    for (int i = 0; i < N; ++i)
        route.at(i) = i;
    double sum_dist = 0;
    int cnt = 0;
    do {
        ++cnt;
        double dist = 0;
        for (int i = 0; i < N - 1; ++i) {
            int j1 = route.at(i);
            int j2 = route.at(i + 1);
            int dx = x_vec.at(j2) - x_vec.at(j1);
            int dy = y_vec.at(j2) - y_vec.at(j1);
            dist += hypot(dx, dy);
        }
        sum_dist += dist;
    } while (next_permutation(route.begin(), route.end()));
    cout << setprecision(10) << sum_dist / cnt << endl;
}
