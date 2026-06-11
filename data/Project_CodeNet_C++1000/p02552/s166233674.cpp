#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long add(long long a, long long b) {
    long long res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

long long sub(long long a, long long b) {
    long long res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

long long mul(long long a, long long b) {
    return (((a % mod) * (b % mod)) % mod);
}

long long potolok(long long a, long long b){   // округление вверх для целых
    return (a + b - 1) / b;
}


long long gcd(long long x, long long y){
    if(y == 0){
        return x;
    }
    if(x > y){
         return gcd(y, x % y);
    }
    else{
         return gcd(x, y % x);
    }
}

bool cmpr(int x, int y){            // сортировка по абсолютной величине
    if(abs(x) < abs(y)) return true;
    else{
        return false;
    }
}

bool comp(pair<int, int> x, pair<int, int> y){  // сортировка по первой компоненте
    if(x.first < y.first)return true;
    else if(x.first == y.first){
        if(x.second < y.second)return true;
        else return false;
    }
    else{
        return false;
    }
}

int main(){
    int x;
    cin >> x;
    if(x == 1)cout << 0 << endl;
    else{
        cout << 1 << endl;
    }
 }
