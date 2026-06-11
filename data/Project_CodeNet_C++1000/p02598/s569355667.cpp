#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    ll l = 0;
    ll r = 1e9 + 5;
    while(r - l > 1){
        ll tmp = (r + l) / 2;
        ll s = 0;
        REP(i, N){
            ll hoge = ceil((double)A[i] / (double)tmp);
            s += hoge - 1;
        }
        if (s <= K) r = tmp;
        else l = tmp;
    }
    cout << r << endl;

    return 0;
}

