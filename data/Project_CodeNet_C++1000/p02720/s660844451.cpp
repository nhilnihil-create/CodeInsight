#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    int k;
    cin >> k;
    vector<ll> lunlun;
    queue<ll> q;
    for (int i = 1; i <= 9; i++) {
        lunlun.push_back(i);
        q.push(i);
    }
    while (lunlun.size() < k) {
        ll x = q.front(); q.pop();
        if (x%10 == 0) {
            lunlun.push_back(x*10);
            q.push(x*10);
            lunlun.push_back(x*10+1);
            q.push(x*10+1);
        }
        else if (x%10 == 9) {
            lunlun.push_back(x*10+8);
            q.push(x*10+8);
            lunlun.push_back(x*10+9);
            q.push(x*10+9);
        }
        else {
            lunlun.push_back(x*10+x%10-1);
            q.push(x*10+x%10-1);
            lunlun.push_back(x*10+x%10);
            q.push(x*10+x%10);
            lunlun.push_back(x*10+x%10+1);
            q.push(x*10+x%10+1);
        }
    }
    cout << lunlun[k-1] << endl;
    return 0;
}