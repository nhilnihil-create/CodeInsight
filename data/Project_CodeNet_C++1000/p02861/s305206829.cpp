#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int n;
int node[8][2];
// double dist[8][8] = {0};

double getDistance(int n1, int n2) {
    /*if (dist[n1][n2] != 0) {
        return dist[n1][n2];
    }*/

    return /*dist[n1][n2] = dist[n2][n1] = */ sqrt(
        double((node[n1][0] - node[n2][0]) * (node[n1][0] - node[n2][0]) +
               (node[n1][1] - node[n2][1]) * (node[n1][1] - node[n2][1])));
}

int main() {
    cin >> n;
    vector<int> index(n);
    for (int i = 0; i < n; i++) {
        cin >> node[i][0] >> node[i][1];
        index[i] = i;
    }

    double sum = 0;
    int n_floor = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            sum += getDistance(index[i], index[i + 1]);
        }
        n_floor++;
    } while (next_permutation(index.begin(), index.end()));

    cout << std::fixed << std::setprecision(15) << sum / n_floor << endl;

    return 0;
}