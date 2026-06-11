#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int solve(){
    int N;
    cin >> N;
    vector <int> a(N);
    REP(i, N)cin >> a[i];
    sort(a.rbegin(),a.rend());
    //最初に来た人は、a[0]
    //適切に割り込む
    ll res = 0;
    for(int i = 1; i < N; ++i)
    {
        res += a[i/2];
    }
    cout << res << endl;

    return 0;

}

int main()
{
    solve();
    return 0;
}
