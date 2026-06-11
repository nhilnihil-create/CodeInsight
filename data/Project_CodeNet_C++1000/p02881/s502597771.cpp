#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long n,d;
    cin >> n;
    d = -1;
    for(long i = 1; i <= sqrt(n); i++) {
        if(n%i==0){
            d = max(i,d);
        }
    }
    long b = n/d;
    cout << b-1 + d-1 <<endl;
}