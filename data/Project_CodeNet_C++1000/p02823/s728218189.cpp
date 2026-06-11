#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long n, a, b;
    long ans = 0;
    cin >> n >> a >> b;
    if((b - a) % 2 == 0){
        cout << (b - a) / 2  << endl;
        return 0;
    }else{
        long twodiff = (b-a)/2;
        long sidediff = min(a-1,n-b);
        cout << twodiff + sidediff + 1<<endl;
    }
}