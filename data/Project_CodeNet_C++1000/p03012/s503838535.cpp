#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
#define DIV0 1000000007
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
int main()
{
    int N;
    cin >> N;
    int W[N];
    int sum1 = 0,sum2 = 0,diff = 10000000;
    REP(i,N){cin >> W[i]; sum1 += W[i];}
    REP(i,N){
        sum2 += W[i];
        sum1 -= W[i];
        diff = min(diff,abs(sum2-sum1));
    }
    fin(diff);
    return 0;
}