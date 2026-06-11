#include<bits/stdc++.h>
//#include <atcoder/all>
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
//using namespace atcoder;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;
int main(){
    int k;
    cin >> k;
    string ans = "";
    rep(i, k){
        ans += "ACL";
    }
    cout << ans << endl;
}

