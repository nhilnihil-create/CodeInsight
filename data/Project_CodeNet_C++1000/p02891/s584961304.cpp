#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    long long K;
    cin >> S >> K;
    int N = S.size();
    long long A = 0;
    long long B = 0;
    long long count = 1;

    if (N == 1){
        cout << K/2 << endl;
        return 0;
    }

    for (int i = 1; i < N; i++) {
        if (S.at(i) == S.at(i-1)){
            count++;
            if (i == N-1){
                if (count == N){
                    cout << N*K/2 << endl;
                    return 0;
                }
                else {
                    A += count/2;
                }
            }
        }
        else {
            A += count/2;
            count = 1;
        }
    }

    S += S;
    count = 1;
    for (int i = 1; i < N*2; i++) {
        if (S.at(i) == S.at(i-1)){
            count++;
            if (i == N*2-1){
                B += count/2;
            }
        }
        else {
            B += count/2;
            count = 1;
        }
    }
    long long C = A + (B-A)*(K-1);
    cout << C << endl;
}
