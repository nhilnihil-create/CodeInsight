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

int N, K;
int main(void){
    cin >> N >> K;
    if(K > (N - 1)*(N - 2) / 2){
        cout << -1 << endl;
        return 0;
    }
    int M = (N-1) + ((N - 1)*(N - 2) / 2 - K);
    cout << M << endl;
    REP(i, N-1) cout << 1 << " " << i + 2 << endl;
    int count = 0;
    for (int i = 2;i <= N; i++){
        for (int j = i+1;j <= N;j++){
            if (count++ >= ((N - 1)*(N - 2) / 2 - K)) break;
            cout << i << " " << j << endl;
        }
        if (count >= ((N - 1)*(N - 2) / 2 - K)) break;
    }
    return 0;
}

