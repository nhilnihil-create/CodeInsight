// g++ -std=c++11 test.cpp && ./a.out
// g++ -std=c++11 bfs.cpp && cat bfs.txt | ./a.out

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>

using namespace std;

#define INF (1<<29)
#define PRINT(A) {for (auto it=A.begin(); it != A.end(); ++it) {cout << *it << ' ';} cout << endl;}
#define SUM(A) accumulate(A.begin(), A.end(), 0)
#define MAX(A) *max_element(A.begin(), A.end())
#define BIT_LENGTH(N) floor(log2(N)) + 1
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RREP(I, N) for (int I = N-1; I >= 0 ; --I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RREPP(I, A, B) for (int I = A; I > (B); --I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I

typedef vector<int> VI;
typedef map<int, int> MII;
typedef set<int> SI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

int main() {
    int N;
    cin >> N;
    cout << (1000 - (N % 1000)) % 1000 << endl;
    return 0;
}