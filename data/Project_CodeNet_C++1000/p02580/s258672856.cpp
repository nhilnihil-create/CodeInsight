#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <assert.h>
#include <unordered_set>
#include <random>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;


#define REP(i, n) for(ll i = 0; i < n; i++)






























int main(){
    int h, w, m;
    scanf("%d %d %d", &h, &w, &m);
    set<pair<int, int>> st;
    vector<int> y(m), x(m);
    vector<pair<int, int>> cnth(h + 1), cntw(w + 1);
    for(int i = 0; i <= h; i++){
        cnth[i].second = i;
    }
    for(int i = 0; i <= w; i++){
        cntw[i].second = i;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &y[i], &x[i]);
        st.insert({y[i], x[i]});
        cnth[y[i]].first++;
        cntw[x[i]].first++;
    }
    sort(cnth.begin(), cnth.end(), greater<pair<int, int>>());
    sort(cntw.begin(), cntw.end(), greater<pair<int, int>>());
    int ans = cnth[0].first + cntw[0].first - 1;
    for(int i = 0; i <= h; i++){
        if(cnth[0].first != cnth[i].first) break;
        for(int j = 0; j <= w; j++){
            if(cntw[0].first != cntw[j].first) break;
            if(st.find({cnth[i].second, cntw[j].second}) == st.end()){
                printf("%d\n", ans + 1);
                return 0;
            }
        }
    }
    printf("%d\n", ans);
}