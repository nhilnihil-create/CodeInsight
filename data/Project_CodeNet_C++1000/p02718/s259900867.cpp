#include<iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    int A[N];
    double sum = 0;
    int popular_product = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        if (sum / 4 / M <= A[i]) {
            popular_product += 1;
        }
    }
    if (popular_product >= M) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
