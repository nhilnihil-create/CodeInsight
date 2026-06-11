#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    map<P, int> ma;
    int max_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            
            int dx = X[i] - X[j];
            int dy = Y[i] - Y[j];
            ma[P(dx, dy)]++;
            max_cnt = max(max_cnt, ma[P(dx, dy)]);
        }
    }

    cout << N - max_cnt << endl;
    return 0;
}