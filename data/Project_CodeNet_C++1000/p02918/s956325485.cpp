#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>

//エイリアス
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    template<typename T>
    vector<T> read_vec(size_t n){
        vector<T> tmp(n);
        for(size_t i = 0; i < n; i++){
            cin >> tmp[i];
        }
        return tmp;
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};



int main(){
    Stream io;
    
    int N, K;
    string S;
    io.read(N, K, S);

    int ans = 0;
    int len = 1;
    char d = S[0];
    for(int i = 1; i < S.size(); i++){
        if(d == S[i]){
            ans++;
        }
        else {
            len++;
            d = S[i];
        }
    }

    if(len % 2 == 0){
        ans += 2 * min(K, (len - 2) / 2);
        K -= (len - 2) / 2;
        if(K > 0) ans++;
    }
    else{
        ans += 2 * min(K, (len - 1) / 2);
    }
    
    cout << ans;

    return 0;
}
