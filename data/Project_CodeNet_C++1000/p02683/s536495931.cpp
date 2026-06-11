#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main()
{
    int n, m, x; cin >> n >> m >> x;
    vector<int> ci(n);
    vector<vector<int> > aij(n, vector<int>(m));
    rep(i, n){
        cin >> ci[i];
        rep(j, m){
            cin >> aij[i][j];
        }
    }

    int ans = -1, cost;
    vector<int> skills(m);
    bool ok;
    rep(bits, 1<<n){
        ok = true;
        cost = 0;
        fill(skills.begin(), skills.end(), 0);

        rep(i, n){
            if(!((bits>>i) & 1)) continue;

            cost += ci[i];
            rep(j, m){
                skills[j] += aij[i][j];
            }
        }

        rep(j, m){
            if(skills[j] < x){
                ok = false;
                break;
            }
        }

        if(ok){
            ans = (ans == -1 ? cost : min(ans, cost));
        }
    }

    cout << ans << endl;
    return 0;
}