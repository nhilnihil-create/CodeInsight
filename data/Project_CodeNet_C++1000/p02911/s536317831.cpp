#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;
typedef long long ll;

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> data(Q);
    for (int i = 0; i < Q; i++) {
        cin >> data.at(i);
    }
    vector<int> point(N + 1, 0);
    for (int i = 0; i < Q; i++) {
        point.at(data.at(i))++;
    }
    for (int i = 1; i <= N; i++) {
        if (point.at(i) > Q - K) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
}