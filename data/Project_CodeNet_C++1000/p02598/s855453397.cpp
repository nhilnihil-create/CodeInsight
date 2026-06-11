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
    int N,K;
    cin >> N >> K;
    vector <int> a(N);
    REP(i, N)cin >> a[i];

    sort(a.rbegin(),a.rend());

    //REP(i, N)cout << a[i] << endl;
    
    //にぶたん Xを実現する
    ll l = 0;
    ll r = a[0];

    while(l+1<r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for(int i = 0; i < N; ++i)
        {
            if(mid < a[i])
            {
                cnt += a[i]/mid;
            }
        }
        if(cnt <= K)r = mid;
        else l = mid;

    }

    cout << r << endl;

    return 0;

}

int main()
{
    solve();
    return 0;
}
