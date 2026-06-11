#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repr(i,n) for(ll i=(n-1);i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define br cout << endl;
using namespace std;
const int INF = 1e9;
const int MOD = 1e9+7;
using Graph = vector<vector<ll>>;
template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true;} return false;}

// 0 false, 1 true 
// string to int : -48
// ceil(a)  1.2->2.0
// c++17	g++ -std=c++17 a.cpp

int main() {
    ll n;
    cin >> n;
    vector<long long> vec(n);
    ll sum;
    vector<ll> sum_before(n);
    vector<ll> sum_after(n);
    rep(i, n){
        cin >> vec.at(i);
        if(i == 0){
            sum_before.at(i) = vec.at(i);
        }else{
            sum_before.at(i) = sum_before.at(i-1) + vec.at(i);
        }
    }
    rep(i,n){
        sum_after.at(i) = sum_before.at(n-1) - sum_before.at(i);
    }

    ll tmp = abs(sum_before.at(0) - sum_after.at(0));
    for(ll i = 1; i < n; i++){
        tmp = min(tmp, abs(sum_before.at(i) - sum_after.at(i)));
    }
    cout << tmp << endl;

}