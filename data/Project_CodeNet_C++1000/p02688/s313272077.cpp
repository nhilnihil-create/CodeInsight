#include<iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int Sunuke[N] = {};
    for (int i = 0; i < K; i++) {
        int d; cin >> d;
        for (int j = 0; j < d; j++) {
            int A; cin >> A;
            Sunuke[A - 1] = 1;
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (Sunuke[i] == 0) {
            answer++;
        }
    }
    cout << answer << endl;
}
