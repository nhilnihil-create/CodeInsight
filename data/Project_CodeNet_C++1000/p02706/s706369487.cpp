#include<iostream>
using namespace std;

int main() {
    int N, M, A;
    cin >> N >> M;

    int sum = 0;
    for(int i = 0; i < M; i++) {
        cin >> A;
        sum += A;
    }

    if (sum > N) cout << -1 << endl;
    else cout << N - sum << endl;

}