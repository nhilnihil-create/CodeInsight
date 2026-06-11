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
    ll N,M,K;
    cin >> N >> M >> K;
    vector <ll> a(N);
    vector <ll> b(M);
    REP(i, N)cin >> a[i];
    REP(i, M)cin >> b[i];

    vector <ll> a_l_Sum(N+1,0);

    for(int i = 0; i < N; ++i)
    {
        a_l_Sum[i+1] = a[i] + a_l_Sum[i];
    }

    vector <ll> b_l_Sum(M+1,0);

    for(int i = 0; i < M; ++i)
    {
        b_l_Sum[i+1] = b[i] + b_l_Sum[i];
    }


    //なぜかdequeでつなげてたがそんなはずはなかった

    //a[0]～a[n-1] + 
    //b[0]～b[m-1]の最善をみつける

    //a[0]とb[0]は固定
    int res = 0;
    //Aの机の本を何冊読むか
    for(int i = 0; i <= N ; ++i)
    {
        //0冊のとき
        if(a_l_Sum[i] + b_l_Sum[0] <= K)
        {
                res = max(res, i);
        }
        int l = 0;
        int r = M+1;
        while (l+1 < r)
        {
            int mid = (l+r)/2;
            if(a_l_Sum[i] + b_l_Sum[mid] <= K)
            {
                l = mid; 
                res = max(res, i + mid);
            }
            else r = mid;
        }
    }

    cout << res << endl;

    return 0;
}

int main()
{
    solve();
    return 0;
}
