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

ll mod = 1000000007;

int main(){
    ll N; cin >> N;
    vll A(N);
    vvll count(N+1, vll(0));
    int col = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(A[i] == 0){col++;}
        count[A[i]].emplace_back(i);
    }
    bool j = true;
    for(int i=0; i<N; i++){
        int k = 0;
        if(A[i] == 0){continue;}
        else{
        if(count[A[i]][0] == i){
            for(auto x: count[A[i]-1]){
                if(x<i){k++;}
            }
            if(k<1){j = false;}
        }
        else if(count[A[i]][1] == i){
            for(auto x: count[A[i]-1]){
                if(x<i){k++;}
            }
            if(k<2){j = false;}
        }
        else{
            for(auto x: count[A[i]-1]){
                if(x<i){k++;}
            }
            if(k<3){j = false;}
        }
        }
    }
    for(auto x:count){
        if(x.size() > 3){
            j = false;
        }
    }
    if(j == false){cout << 0;}
    else{
    if(col == 1){cout << 3;}
    else if(col == 2){
        ll res = 6;
        for(int i=0; i<N; i++){
            if(A[i] == 0){continue;}
            else{
                int k = 0;
                for(auto x:count[A[i]-1]){
                    if(x < i){k++;}
                }
                if(count[A[i]][0] == i&&k==2){
                    res *= 2;
                }
            }
            res %= mod;
        }
        res %= mod;
        cout << res;
    }
    else{
        ll res = 6;
        for(int i=0; i<N; i++){
            if(A[i] == 0){continue;}
            else{
                int k = 0;
                for(auto x:count[A[i]-1]){
                    if(x < i){
                        k++;
                    }
                }
                if(count[A[i]][1]==i){
                    k--;
                }
                else if(count[A[i]][2] == i){
                    k -= 2;
                }
                res *= k;
            }
            res %= mod;
        }
        cout << res;
    }
    }
}