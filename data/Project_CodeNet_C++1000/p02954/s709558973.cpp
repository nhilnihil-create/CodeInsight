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
    string s;
    cin >> s;
    v1 atLR(0);
    int n = s.size();
    v1 ans(n, 0);
    rep(i, n-1){
        if(s[i] == 'R' && s[i+1] == 'L'){
            atLR.push_back(i);
        } 
    }
    if(s[n-2] == 'R') atLR.push_back(n-2);
    int N = atLR.size();
    for(int j = 0; j <= atLR[0]; j++){
        if((atLR[0]-j)%2 == 0) ans[atLR[0]]++;
        else ans[atLR[0]+1]++;
    }
    for(int i = 0; i <N-1; i++){
        for(int j = atLR[i]+1; j <= atLR[i+1]; j++){
            if(s[j] == 'L'){
                if((atLR[i] - (j-1))%2 == 0) ans[atLR[i]+1]++;
                else ans[atLR[i]]++;
            }else{
                if((atLR[i+1] - j)%2 == 0) ans[atLR[i+1]]++;
                else ans[atLR[i+1]+1]++;
            }
        }
    }
    for(int j = atLR[N-1]+1; j < n; j++){
        if((atLR[N-1]-(j-1))%2 == 0) ans[atLR[N-1]+1]++;
        else ans[atLR[N-1]]++;
    }
    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;
}