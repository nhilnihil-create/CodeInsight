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
    int n;
    cin >> n;
    vl H(n);
    rep(i,n){
        cin >> H[i];
    }
    bool judge = true;
    if(H.size() == 1){
        cout << "Yes" << endl;
        return 0;
    }
    for(int i = n-1; i > 0; i--){
        if(H[i] < H[i-1]-1){
            cout << "No" << endl;
            judge = false;
            break;  
        }else if(H[i] < H[i-1]) H[i-1]--;
    }
    if(judge){
        if(H[0]-1 <= H[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}