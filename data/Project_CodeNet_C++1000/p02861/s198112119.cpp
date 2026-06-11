#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> towns(N, make_pair(0, make_pair(0, 0)));
    for (int i = 0; i < N; ++i) {
        towns[i].first = i;
        cin >> towns[i].second.first >> towns[i].second.second;
    }

    double sum = 0;
    do {
        for (int i = 1; i < N; ++i) {
            int x0 = towns[i - 1].second.first;
            int y0 = towns[i - 1].second.second;
            int x1 = towns[i].second.first;
            int y1 = towns[i].second.second;
            sum += sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
        }
    } while (next_permutation(towns.begin(), towns.end()));
    for (int i = 2; i <= N; ++i) {
        sum /= i;
    }
    cout << sum << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
