#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
//#define DEBUG
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
    cin >> n >>  m;
    vector<pair<int, int>> ab(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab.begin(), ab.end());
    DEBUG_VAL("ab", ab[n-1].first);
    ll ans = 0;
    priority_queue<int> Q;
    int j = 0;
    for(int i = 1;i <=m; i++){
        DEBUG_VAL("i", i);
        while(j < n && ab[j].first <= i){
            Q.push(ab[j].second);
            j++;
        }
        if(!Q.empty()){
            ans += Q.top();
            Q.pop();
        }
    }
    cout << ans << endl;
}