#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

inline ll func(ll x){
    return x*(x-1)/2;
}

int main(){
    int N;
    cin >> N;
    vint A;
    map<int,ll> mp;
    REP(i,N){
        int a;
        cin >> a;
        A.pb(a);
        mp[a]++;
    }

    ll total = 0;
    for(auto p:mp){
        total += func(p.second);
    }
    for(auto a : A){
        cout << total - (mp[a]-1) << endl;
    }
}