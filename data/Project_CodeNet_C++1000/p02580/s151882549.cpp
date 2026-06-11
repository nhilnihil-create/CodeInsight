#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pll> vpll;

#define INX(x) (cin >> x)
#define OUTX(x) (cout << x << endl)

#define ADD emplace_back
#define MP make_pair
#define VVEC(type) vector<vector<type>>

int main()
{
    ll H, W, M;
    cin >> H >> W >> M;

    vpll bomb;
    vll rcount(H+1, 0);
    vll ccount(W+1, 0);
    for (ll i = 0; i < M; i++)
    {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        rcount[tmp1]++;
        ccount[tmp2]++;
        bomb.ADD(MP(tmp1,tmp2));
    }
    
    ll rmax = 0;
    vll rmaxindex;
     for (ll i = 1; i <= H; i++)
    {
        if(rmax < rcount[i])
        {
            rmax = rcount[i];
            rmaxindex.resize(0);
            rmaxindex.ADD(i);
        }
        else if(rmax == rcount[i])
        {
            rmaxindex.ADD(i);
        }
    }

    ll cmax = 0;
    vll cmaxindex;
     for (ll i = 1; i <= W; i++)
    {
        if(cmax < ccount[i])
        {
            cmax = ccount[i];
            cmaxindex.resize(0);
            cmaxindex.ADD(i);
        }
        else if(cmax == ccount[i])
        {
            cmaxindex.ADD(i);
        }
    }

    sort(bomb.begin(), bomb.end());

    ll result = rmax + cmax;
    bool isFound = false;
    for(auto x : rmaxindex)
    {
        for(auto y : cmaxindex)
        {
            if(binary_search(bomb.begin(), bomb.end(), MP(x, y)))
            {
                continue;
            }
            else
            {
                isFound = true;
                break;
            }
        }

        if(isFound)
        {
            break;
        }
    }
    cout << (isFound ? result : result - 1) << endl;


    return 0;
}
