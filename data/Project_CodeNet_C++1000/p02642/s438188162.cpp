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
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<bool> v(A[N-1]+ 1, true);
    int ans = 0;
    REP(i, N){

        if (!v[A[i]]) continue;
        int tmp = A[i];
        while(tmp <= A[N-1]){
            v[tmp] = false;
            tmp += A[i];
        }
        if ((i < N - 1 && A[i] == A[i+1]) || (i > 0 && A[i] == A[i-1])) {
            continue;
        }
        //cout << A[i] << endl;
        ans++;
    }
    cout << ans << endl;




    return 0;
}