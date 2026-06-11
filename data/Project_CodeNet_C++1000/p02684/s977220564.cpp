#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define ArraySizeOf(array)     (sizeof(array) / sizeof(array[0]))
#define res(i,n) for(int i=n;;i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define REV(i,n) for(int i=n-1;i>0;i--)
#define req(i,n,m) for(int i=n;i<m;i++)
#define REQ(i,n,m,l) for(int i=n;i<m;i+=l) 
#define _GLIBCXX_DEBUG
int INF = 1e9 + 7;
long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998626034825342117;
unsigned NthDayOfWeekToDay(unsigned n, unsigned dow, unsigned dow1){unsigned day;if (dow < dow1) dow += 7;day = dow - dow1;day += 7 * n - 6;return day;}
signed gcd(long long x, long long y) {if (y == 0)return x;return gcd(y, x % y);}
signed lcm(long long x, long long y){return x / gcd(x, y) * y;}
unsigned DayToWeekNumber(unsigned day){return (day - 1) / 7 + 1;}
unsigned AnotherDayOfWeek(unsigned day, unsigned day0, unsigned dow0){return (dow0 + 35 + day - day0) % 7;}
using namespace std;
int main() {
    long long N, K; cin >> N >> K;
    vector<int>A(N);
    vector<bool>B(N, false);
    B[0] = true;
    for (int i = 0; i < N; i++)cin >> A[i];
    vector<int>C(N+1);
    C[0] = 0;
    for (long long i = 1; i < N+1; i++) {
        C[i] = A[C[i-1]]-1;
        if (B[A[C[i]]] == true) {
            for (long long j = 0; j < i; j++) {
                if (C[j] == C[i]) {
                    int a=(K-(j+1))%(j-i);
                    cout << C[j+a+1]+1 << endl;
                    return 0;
                }
            }
        }
        B[A[C[i]]] = true;
        if(i==K){
          cout<<C[i]+1<<endl;
          return 0;
        }
    }
    cout<< C[K%N]+1 <<endl;
}