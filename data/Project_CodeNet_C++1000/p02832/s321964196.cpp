#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >>n;
    vector<int> bricks(n);
    bool flag = false;
    rep(i,n) {
        cin >> bricks[i];
        if (bricks[i] == 1) flag = true;
    }

    if (!flag) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 1;
    int ans = 0;
    rep(i,n){
        if(bricks[i]==cnt) cnt ++;
        else ans++;
    }

    cout << ans <<endl;
}