#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    vl pow2(41, 1);
    for(int i =1; i<=40;i++){
        pow2[i] = pow2[i-1]*2;
    }
    vl powsum(41, 0);
    powsum[0] = 0;
    for(int i = 1; i <= 40; i++){
        powsum[i] = powsum[i-1]+pow2[i-1];
    }
    vl attack(41, 0);
    for(int i = 0; i <=40; i++){
        attack[i] = pow2[i] + powsum[i];
    }
    ll H;
    cin >> H;
    int l = 0;
    int r = 41;
    while(l+1 < r){
        ll m = (r+l)/2;
        if(H > pow2[m]) l = m;
        else if(H < pow2[m]) r = m;
        else{
            l = m;
            break;
        }
    }
    cout << attack[l] <<endl;
}