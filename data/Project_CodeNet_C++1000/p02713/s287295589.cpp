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

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(){
    int k;
    ll sum = 0;
    cin >> k;
    for(int i = 1;i<= k; i++){
        for(int j= 1; j<= k; j++){
            for(int l=1;l<= k; l++){
                sum += gcd(l, gcd(i,j));
            }
        }
    }
    cout << sum << endl;
}