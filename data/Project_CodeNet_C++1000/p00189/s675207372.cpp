#include <iostream>
#include <cstring>
using namespace std;

#define MAX_V 10
#define MAX_E 45
#define INF 1<<28
int d[MAX_V][MAX_V];
int n;
int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < MAX_V; i++) {
            for (int j = 0; j < MAX_V; j++) {
                if (i == j) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = INF;
                }
            }
        }
        int biggest_c = 0;
        for (int i = 0; i < n; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            d[from][to] = weight;
            d[to][from] = weight;
            if (biggest_c < to) biggest_c = to;
        }

//        for (int i = 0; i <= biggest_c; i++) {
//            for (int j = 0; j <= biggest_c; j++) {
//                cout << d[i][j] << ' ';
//            }
//            cout <<endl;
//        }

        for (int k = 0; k <= biggest_c; k++) {
            for (int i = 0; i <= biggest_c; i++) {
                for (int j = 0; j <= biggest_c; j++) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        int sums[biggest_c];
        for (int i = 0; i <= biggest_c; i++) {
            sums[i] = 0;
        }
        int min_sum = INF;
        int best_city = INF;
        for (int i = 0; i <= biggest_c; i++) {
            for (int j = 0; j <= biggest_c; j++) {
                sums[i] += d[i][j];
//                cout << d[i][j] << ' ';
            }
//            cout << endl;
        }
        for (int i = 0; i <= biggest_c; i++) {
            if (min_sum > sums[i]) {
                min_sum = sums[i];
                best_city = i;
            }
        }

        cout << best_city << ' ' << min_sum << endl;
    }
    return 0;
}