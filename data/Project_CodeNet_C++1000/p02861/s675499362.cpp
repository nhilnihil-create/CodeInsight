#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector<vector<double>> d(N, vector<double>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            d[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
        }
    }
    vector<int> S(N);
    for(int i = 0; i < N; i++) {
        S[i] = i;
    }
    vector<double> ans;
    do {
        double l = 0;
        for(int i = 0; i < N - 1; i++) {
            l += d[S[i]][S[i + 1]];
        }
        ans.push_back(l);
    } while(next_permutation(S.begin(), S.end()));
    double a = 0;
    for(int i = 0; i < ans.size(); i++) {
        a += ans[i];
    }
    cout << fixed << setprecision(10) << a / (double)ans.size() << endl;
    return 0;
}