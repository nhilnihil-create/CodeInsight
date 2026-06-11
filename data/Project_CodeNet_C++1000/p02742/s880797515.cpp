#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    ll h, w;
    cin >> h >> w;
    if(min(h,w)==1){
        cout << 1 <<endl;
        return 0;
    }
    ll hw = h*w;
    cout<<(hw+1)/2<<endl;
}