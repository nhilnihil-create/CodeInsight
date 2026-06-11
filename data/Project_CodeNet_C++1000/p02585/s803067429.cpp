#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const ll INF = 3e18;
int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> p(n);
    vector<ll> c(n);

    for(int i = 0;i < n;i++){
        cin >> p[i];
        p[i]--;
    }
    
    for(int i = 0;i < n;i++)cin >> c[i];

    vector<bool> used(n,false);
    ll ans = -INF;
    for(int i = 0;i < n;i++){
        int now = i;
        vector<ll> costs;
        while(used[now] == false){
            costs.push_back(c[now]);
            used[now] = true;
            now = p[now];
        }
        
        if(costs.size() == 0)continue;
        vector<ll> max_sum(costs.size()+1,-INF);

        for(int j = 1;j <= costs.size();j++){
            ll now_sum = 0;
            for(int l = 0;l < j;l++)now_sum += costs[l];
            max_sum[j] = now_sum;
            for(int l = 1;l < costs.size();l++){
                now_sum -= costs[l-1];
                now_sum += costs[(l+j-1) % costs.size()];
                max_sum[j] = max(max_sum[j],now_sum);
            }
        }


        for(ll j = 1;j <= costs.size();j++){
            ll rem = max_sum[j];
            ll cnt = k - j;
            if(cnt >= 0){
                ans = max(ans,rem);
                ans = max(ans,cnt / (ll)costs.size() * max_sum[costs.size()] + rem);
            }
        }
    }
    cout << ans << '\n';
}
