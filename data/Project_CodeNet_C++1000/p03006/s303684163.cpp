#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm> // sort
#include <map>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
using namespace std;

int main(){
    int N;
	cin >> N;
    if(N == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<long long> x(N);
    vector<long long> y(N);

    REP(i,N)
    {
        cin >> x[i] >> y[i];
    }

	int res = N;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {

            if(i == j)continue;
            //各2点間の距離を全て試して最小値を導く
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];

            int sub = 0;
            for(int i2 = 0; i2 < N; ++i2)
            {
                for(int j2 = 0; j2 < N; ++j2)
                {
                    if(i2 == j2)continue;
                    if(dx == x[j2]-x[i2] && dy == y[j2]- y[i2])
                    {
                        ++sub;
                    }

                    res = min(res, N - sub);
                }
            }
        }
    }

	cout << res << endl;


    return 0;    
}

