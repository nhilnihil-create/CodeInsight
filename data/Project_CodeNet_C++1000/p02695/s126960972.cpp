#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <time.h>
#include <functional>

//#include "All.h"

using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    REP(i, b) tmp *= a;
    return tmp;
}

ll N, M, Q;
ll a[110], b[110], c[110], d[110];
ll A[110] = {};

ll ans = 0;

void Amaker(int n, int i) {
    //nはn+1番目のループであることを表す
    //iはA[n]の初期値
    for (A[n] = i; A[n] < M; A[n]++) {
        if (n == N - 1) {
            //処理
            //ここでAの数列確定
            ll tmp = 0;
            /*
            cout << "A[]:";
            REP(j, N) {
                cout << A[j] + 1 << " ";
            }
            cout << endl;
            */
            REP(j, Q) {
                //そのAに対してQ回確かめる
                if (A[b[j] - 1] - A[a[j] - 1] == c[j]) {
                    tmp += d[j];
                    //cout << a[j] << " " << b[j] << " " << c[j] << " " << d[j] << endl;
                }
            }
            ans = max(ans, tmp);
        }
        else {
            Amaker(n + 1, A[n]);
        }
    }
}

int main() {
    cin >> N >> M >> Q;
    REP(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    Amaker(0, 0);
    /*
    for (A[0] = 0; A[0] < M; A[0]++) {
        for (A[1] = A[0]; A[1] < M; A[1]++) {
            for (A[2] = A[1]; A[2] < M; A[2]++) {
                for (A[3] = A[2]; A[3] < M; A[3]++) {
                    for (A[4] = A[3]; A[4] < M; A[4]++) {
                        for (A[5] = A[4]; A[5] < M; A[5]++) {
                            for (A[6] = A[5]; A[6] < M; A[6]++) {
                                for (A[7] = A[6]; A[7] < M; A[7]++) {
                                    for (A[8] = A[7]; A[8] < M; A[8]++) {
                                        for (A[9] = A[8]; A[9] < M; A[9]++) {
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    */
    cout << ans << endl;
}

/*
10 10 2
1 10 9 1
2 10 9 2
*/
