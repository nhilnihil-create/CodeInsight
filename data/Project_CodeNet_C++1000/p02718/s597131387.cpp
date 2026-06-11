
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void Main() {
    // input
    int N, M;
    cin >> N >> M;

    vector<int> votes(N);
    for (int i = 0; i < N; i++) {
        cin >> votes[i];
    }

    // translate
    sort(votes.begin(), votes.end());
    reverse(votes.begin(), votes.end());

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += votes[i];
    }

    for (int i = 0; i < M; i++) {
        if (votes[i] < sum * 1.0 / (4 * M)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
