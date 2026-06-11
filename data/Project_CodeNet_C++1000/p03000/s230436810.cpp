#include "bits/stdc++.h"
using namespace std;

int main() {

    int N, X;
    cin >> N >> X;

    int sum = 0;
    int count = 1;
    vector<int> data(N);
    for (int i = 0; i < N;i++) {
        cin >> data.at(i);
    }
    for (int i = 0; i < N;i++) {
        sum = sum + data.at(i);
        if (X >= sum ) {
            count = count + 1;
        }
        else {
            break;
        }
    }

    cout << count << endl;
}