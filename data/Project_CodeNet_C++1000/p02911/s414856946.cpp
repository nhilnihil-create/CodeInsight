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
    ll n, k, q;
    cin >> n >> k >> q;
    v1 a(n, 0);
    rep(i,q){
        int A;
        cin >> A;
        A--;
        a[A]++;
    }
    rep(i, n){
        if(q-a[i] >= k) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}