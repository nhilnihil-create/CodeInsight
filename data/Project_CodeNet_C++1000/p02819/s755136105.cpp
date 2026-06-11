#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool judge(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}
int main() {
    int x;
    cin >> x;
    int num = x;
    while(1) {
        if(judge(num)) {
            cout << num << endl;
            ;
            break;
        }
        num++;
    }
    return 0;
}
