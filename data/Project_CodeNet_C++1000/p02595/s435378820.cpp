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

int main() {
    int N;
    long D;
    cin >> N >> D;
    VVI points;
    int ans = 0;
    REP(i, N) {
        long X, Y;
        cin >> X >> Y;
        if (X*X + Y*Y <= D*D) {
            ans += 1; 
        }
    }
    cout << ans << endl;
    return 0;
}