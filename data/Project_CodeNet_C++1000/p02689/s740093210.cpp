#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fm, ...) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout << "DEBUG PRINT ";std::printf(fm, __VA_ARGS__);}while(0)
#define DEBUG_VAL(a, b) do{std::printf("%s:%d(%s)", __FILE__, __LINE__, __func__);std::cout <<"DEBUG VAL " << a << ":" << b << endl;}while(0)
#else
#define DEBUG_PRINT(...)do{}while(0);
#define DEBUG_VAL(a, b)do{}while(0);
#endif

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int n, m;
    cin >> n >> m;
    v1 H(n);
    rep(i, n){
        cin >> H[i];
    }
    vector<set<int>> AB(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        AB[a].insert(b);
        AB[b].insert(a);
    }
    int ans = 0;
    v2 height(n, v1(0));
    rep(i, n){
        auto itr = AB[i].begin();
        rep(j, AB[i].size()){
            if(j != 0) itr++;
            height[i].push_back(H[*itr]);
        }
        sort(height[i].begin(), height[i].end());
        int s = height[i].size();
        if(s == 0) ans++;
        else{
            if(height[i][s-1] < H[i]) ans++;
        }
    }
    
    cout << ans << endl;
}