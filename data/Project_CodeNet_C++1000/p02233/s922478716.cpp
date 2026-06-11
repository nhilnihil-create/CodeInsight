#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iomanip>
using namespace std;
  
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int (i)=(int)(n)-1;i>=0;i--)
#define REMOVE(Itr,n) (Itr).erase(remove((Itr).begin(),(Itr).end(),n),(Itr).end())
typedef long long ll;

long long FibonacciNumber(long long n, long long mod) {
    long long A[2][2] = {{1, 1}, {1, 0}};
    long long M[2][2] = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n & 1) {
            long long M_00 = M[0][0] * A[0][0] + M[0][1] * A[1][0];
            long long M_01 = M[0][0] * A[0][1] + M[0][1] * A[1][1];
            long long M_10 = M[1][0] * A[0][0] + M[1][1] * A[1][0];
            long long M_11 = M[1][0] * A[0][1] + M[1][1] * A[1][1];
            M[0][0] = M_00 % mod;
            M[0][1] = M_01 % mod;
            M[1][0] = M_10 % mod;
            M[1][1] = M_11 % mod;
        }
        long long A_00 = A[0][0] * A[0][0] + A[0][1] * A[1][0];
        long long A_01 = A[0][0] * A[0][1] + A[0][1] * A[1][1];
        long long A_10 = A[1][0] * A[0][0] + A[1][1] * A[1][0];
        long long A_11 = A[1][0] * A[0][1] + A[1][1] * A[1][1];
        A[0][0] = A_00 % mod;
        A[0][1] = A_01 % mod;
        A[1][0] = A_10 % mod;
        A[1][1] = A_11 % mod;
        n >>= 1;
    }
    return M[1][0];
}

int main() {

    ll n; cin >> n;
    cout << FibonacciNumber(n + 1, 1e18) << endl;
   
    return 0;
}