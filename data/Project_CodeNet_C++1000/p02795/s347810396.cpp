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
    ll H, W, N; cin >> H >> W >> N;
    ll p = max(H, W);
    if(N%p==0){cout << N/p;}
    else{cout << N/p+1;}
}