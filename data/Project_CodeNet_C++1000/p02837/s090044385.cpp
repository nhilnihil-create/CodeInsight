#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll = long long;

using namespace std;

signed main() {
    int N;cin >> N;
    vector<int> A;
    vector<vector<pair<int, int>>> v;
    for(int i = 0;i < N;i++){
        int a;cin >> a;
        A.push_back(a);
        vector<pair<int, int>> w;
        for(int i = 0; i < a;i++){
            int x,y;cin >> x >> y;
            w.push_back({x, y});
        }
        v.push_back(w);
    }
    vector<int> bits(N);
    auto a = [&](){
        for(int i = 0;i < N;i++){
            if(bits[i])
                for(int j = 0;j < A[i];j++){
                    if(bits[v[i][j].first - 1] != v[i][j].second){
                        return false;
                    }
                }            
        }
        return true;
    };
    ll ans = 0;
    function<void(int)> f = [&](int i){
        if(i == N){
            if(a()){
               ans = max(ans, ll(count(bits.begin(), bits.end(), 1))); 
            }
            return;
        }
        bits[i] = 1;f(i + 1);
        bits[i] = 0;f(i + 1);
    };
    f(0);
    cout<<ans<<endl;
}


