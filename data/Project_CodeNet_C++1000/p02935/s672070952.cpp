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
    
    ll N;
    io.read(N);
    auto v = io.read_vec<int>(N);

    priority_queue<double, vector<double>, greater<double>> q;

    for(int i = 0; i < N; i++){
        q.push(v[i]);
    }
    while(q.size() > 1){
        double tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        q.push(tmp / 2);
    }

    cout << fixed << setprecision(5) << q.top();
    return 0;
}
