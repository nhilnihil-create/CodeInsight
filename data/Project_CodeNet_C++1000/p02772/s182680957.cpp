#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int N;
    cin >> N;
    int a;
    rep(i, N) {
        scanf("%d",&a);
        if(a % 2 == 0) {
            if(a % 5 != 0 && a % 3 != 0) {
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}