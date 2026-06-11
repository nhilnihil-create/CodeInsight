#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n,m;cin>> n >> m;
    priority_queue<int> q;
    for(int i = 0; i < n; i++) {
        int a;cin >> a;
        q.push(a);
    }

    for(int i = 0; i < m; i++) {
        int x=q.top();
        q.pop();
        x/=2;
        q.push(x);
    }

    ll sum=0;
    for(int i = 0; i < n; i++) {
        int x=q.top();
        q.pop();
        sum += x;
    }
    cout << sum << endl;

    return 0;
}