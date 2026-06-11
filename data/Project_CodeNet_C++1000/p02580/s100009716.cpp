#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm> // sort
#include <math.h>
#include <map>
#include <set>

#define DEBUG 0

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll MOD = 1000000007;
static const ll INF = 1000000000000000000LL;
                    //999999997000000003
                    //1000000000000000000

using namespace std;

int solve(){
    ll H,W,M;
    cin >> H >> W >> M;
    
    set <pair<ll,ll>> st;

    REP(i,M)
    {
        ll a,b;
        cin >> a >> b;
        st.insert({a,b});
    }

    map <ll,ll> mph,mpw;
    ll hmaxval = 0;
    ll wmaxval = 0;
    vector <ll> hmax,wmax;
    for(auto tmp: st)
    {
        //最も爆弾が設定されている行と列
        hmaxval = max(hmaxval,++mph[tmp.first]);
        wmaxval = max(wmaxval,++mpw[tmp.second]);
    }
    for(auto tmp:mph)
    {
        if(hmaxval == tmp.second)hmax.push_back(tmp.first);
    }
    for(auto tmp:mpw)
    {
        if(wmaxval == tmp.second)wmax.push_back(tmp.first);
    }


    ll res = hmaxval + wmaxval -1;
    for(auto h: hmax)
    {
        for(auto w: wmax)
        {
            if(st.find({h,w}) == st.end())
            {
                ++res;
                cout << res << endl;
                return 0;
            }
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
