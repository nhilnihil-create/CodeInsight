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
using namespace std;

using ll = long long;

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

void add(pair<ll, ll>& p, pair<ll, ll> q){
    p.first += q.first;
    p.second += q.second;
}

ll inp(pair<ll, ll> p, pair<ll, ll> q){
    return p.first * q.first + p.second * q.second;
}

ll oup(pair<ll, ll> p, pair<ll, ll> q){
    return p.first * q.second - p.second * q.first;
}

int main(){
    Stream io;
    
    int N;
    io.read(N);
    vector<pair<ll, ll>> p;
    for(int i = 0; i < N; i++){
        ll x, y;
        io.read(x, y);
        if(x == 0 && y == 0) continue;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end(), [](const auto& a, const auto& b){
        ll o = oup(a, b);
        ll i = inp(a, b);
        pair<ll, ll> stnd = make_pair(1LL, 0LL);
        if(o == 0) {
            if(i > 0) { 
                return false;
            }
            if(oup(stnd, a) > 0) {
                return true;
            }
            if(a.first > 0 && a.second == 0){
                return true;
            }
            return false;
        }
        if(o > 0){
            return !(oup(a, stnd) > 0 && oup(stnd, b) >= 0);
        }
        return (oup(b, stnd) > 0 && oup(stnd, a) >= 0);
    });
    ll ans = 0;
    for(int i = 0; i < p.size(); i++){
        for(int j = 0; j < p.size(); j++){
            pair<ll, ll> sum = make_pair(0L, 0L);
            if(i > j){
                for(int k = i; k < p.size(); k++){
                    add(sum, p[k]);
                }
                for(int k = 0; k <= j; k++){
                    add(sum, p[k]);
                }
            }
            else{
                for(int k = i; k <= j; k++){
                    add(sum, p[k]);
                }
            }
            ans = max(ans, inp(sum, sum));
        }
    }
    cout << fixed << setprecision(10) << sqrt(ans);
    return 0;
}