#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

ll M = 998244353;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    for(int i=0; i<n; i++){
        res *= a;
        res %= mod;
    }
    return res;
}

int main(){
    ll N; cin >> N;
    vll d(N+1);
    for(int i=1; i<N+1; i++){
        cin >> d[i];
    }
    vll num(N, 0);
    for(int i=1; i<N+1; i++){
        num[d[i]]++;
    }
    if(d[1]!=0||num[0]>1){
        cout << 0;
    }else{
        bool t = true;
        for(int i=1; i<N-1; i++){
            if(num[i]==0&&num[i+1]>0){
                t = false;
            }
        }
        if(t == false){
            cout << 0;
        }else{
            ll p = 1;
            for(int i=1; i<N; i++){
                if(num[i]==0){
                    break;
                }else{
                    ll m = modpow(num[i-1], num[i], M);
                    p *= m;
                    p %= M;
                }
            }
            cout << p;
        }
    }
}