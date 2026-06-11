#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define ll long long int
#define rep(i,k,n) for(int i = k; n > i; i++)
#define REP(i,n) rep(i,0,n)

int main(){
    int n;
    long double Pi4 = atan((long double)1);
    cin >> n;
    vector<pair<long double,long double>> b(n); 

    map<long double, vector<int>> c;
    rep(i,1,n + 1) {
        cin >> b[i-1].first >> b[i-1].second;

        long double theta = atan2(b[i-1].second, b[i-1].first);
        long double t[2] = {theta + Pi4 * 2, theta - Pi4 * 2};
        
        c[t[1]].push_back(-i);
        c[t[0]].push_back(i);
        c[t[1] + Pi4 * 8].push_back(-i);
        c[t[0] + Pi4 * 8].push_back(i);
        c[t[1] - Pi4 * 8].push_back(-i);
        c[t[0] - Pi4 * 8].push_back(i);

        c[t[1] + Pi4 * 16].push_back(-i);
        c[t[0] + Pi4 * 16].push_back(i);
        c[t[1] - Pi4 * 16].push_back(-i);
        c[t[0] - Pi4 * 16].push_back(i);
    }

    long double ans = 0;
    set<int> cand;
    for(auto itr : c){
        for(auto v : itr.second){
            if(v > 0)
                cand.insert(v-1);
            if(v < 0 && cand.count(-v-1)){
                cand.erase(-v-1);
            }
        }


        long double x = 0,y = 0;
        for(auto p : cand){
            x += b[p].first;
            y += b[p].second;
        }
        ans = max(ans, sqrt(x * x + y * y));
    }

printf("%.11llf\n", ans);

    return 0;
} 