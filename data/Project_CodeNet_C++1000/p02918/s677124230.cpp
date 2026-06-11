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

int main(){
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    ll m = 0;
    for(int i=0; i<N; i++){
        if(S[i] == 'L'){
            if(i != 0){
                if(S[i-1] == 'L'){m++;}
            }
        }else{
            if(i != N-1){
                if(S[i+1] == 'R'){m++;}
            }
        }
    }
    ll t = 0;
    for(int i=1; i<N; i++){
        if(S[i]!=S[i-1]){t++;}
    }
    if(t/2 >= K){
        cout << m + 2*K;
    }else{
        if(t%2==0){cout << m + 2*(t/2);}
        else{cout << m + 2*(t/2) + 1;}
    }
}