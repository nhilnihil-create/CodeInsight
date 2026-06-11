// g++ -std=c++11 test.cpp && ./a.out
// g++ -std=c++11 bfs.cpp && cat bfs.txt | ./a.out

#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <numeric>
#include <math.h>

using namespace std;

#define PRINT(A) {for (int i = 0; i < A.size(); i++) { cout << A[i] << " ";} cout << endl;}
#define SUM(A) accumulate(A.begin(), A.end(), 0)
#define MAX(A) *max_element(A.begin(), A.end())
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

bool solve(int K){
    if (K%7 == 0) {
        K = K/7;
    }
    int num = 0;
    REP(i, K) {
        num = (num * 10 + 1) % K;
        if (num == 0) {
            cout << i+1 << endl;
            return true;
        }
    }
    return false;
}

int main() {
    int K;
    cin >> K;

    if (!solve(K)) {
        cout << -1 << endl;
    }
    return 0;
}