#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int i, j, n, k, h;
    cin >> n >> k;

    vector<ll> p(n), c(n);

    for(i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    for(i = 0; i < n; i++)
        cin >> c[i];
    
    ll bestAns = LONG_LONG_MIN;
    for(i = 0; i < n; i++){
        vector<ll> cost(n + 2, 0);
        int ini = i;
        for(j = 1, h = p[ini]; ; h = p[h], j++){
            cost[j] = cost[j - 1] + c[h];
            if (h == ini)
                break;
        }
        int loops = k / j;
        ll ans = LONG_LONG_MIN;
        if (loops)
            ans = max(*max_element(&cost[1], &cost[j + 1]), cost[j] * loops);
        if (cost[j] >= 0 && loops == 1){
            ans = max(ans, *max_element(&cost[0], &cost[(k % j) + 1]) + cost[j] * loops);
        }
        else if (cost[j] >= 0 && loops > 1){
            ans = max(max(ans, *max_element(&cost[0], &cost[(k % j) + 1]) + cost[j] * loops), *max_element(&cost[0], &cost[j + 1]) + cost[j] * (loops - 1));
        }
        else{
            ans = max(ans, *max_element(&cost[1], &cost[min(j, k) + 1]));
        }
        bestAns = max(bestAns, ans);
    }
    cout << bestAns << endl;
}