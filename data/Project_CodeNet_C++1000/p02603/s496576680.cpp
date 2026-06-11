#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    long long money = 1000;
    for (int i = 1; i < N; i++) {
        if (A[i - 1] < A[i]) {
            money = money / A[i - 1] * A[i] + money % A[i - 1];
        }
    }
    cout << money << endl;
}
