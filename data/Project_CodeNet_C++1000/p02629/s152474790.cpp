#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(ll N){

    string res;
    ll t = 26;
    ll idx = 0;

    while(idx + t < N){
        idx += t;
        t *= 26;
    }

    idx = N - idx - 1;
    while(t > 26){
        t /= 26;
        res += (idx / t) + 'a';
        idx %= t;
    }
    
    res += (N - 1) % t + 'a';
    return res;
}

int main(){

    ll N;
    cin >> N;

    cout << solve(N);
    return 0;
}