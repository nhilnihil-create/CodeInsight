#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main(void)
{
    ll h, w, k, ans = 0;
    cin >> h >> w >> k;
    vector<vector<char>>  c(h, vector<char>(w));
    vector<bool>  he(h), wi(w);
    for(ll i = 0; i < h; i++)
        for(ll j = 0; j < w; j++)
            cin >> c.at(i).at(j);
    
    for(ll i = 0; i < (1 << h); i++) {
        for(ll j = 0; j < h; j++) {
            if(1 & (i >> j))
                he.at(j) = false;
            else
                he.at(j) = true;
        }

        for(ll j = 0; j < (1 << w); j++) {
            ll num = 0;
            for(ll k = 0; k < w; k++) {
            if(1 & (j >> k))
                wi.at(k) = false;
            else
                wi.at(k) = true;
            }

            for(ll k = 0; k < h; k++)
                for(ll l = 0; l < w; l++)
                    if(he.at(k) && wi.at(l) && c.at(k).at(l) == '#')
                        num++;

            if(num == k)
                ans++;
        }
    }

    cout << ans;

}