#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int N;
int d[100000];
int main(void){
    cin >> N;
    REP(i,N) cin >> d[i];
    sort(d, d+N);
    cout << d[N/2] - d[N/2 - 1] << endl;
    return 0;
}

