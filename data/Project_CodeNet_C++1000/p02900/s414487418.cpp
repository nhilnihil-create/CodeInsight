#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
int main() {
    long long ans = 1;
    long long A, B;
    cin >> A >> B;
    long long MIN = min(A, B), MAX = max(A, B);
    vector<long long> a = divisor(MIN);
    queue<long long> q;
    for(long long x : a) {
        if(MAX % x == 0)
            q.push(x);
    }
    q.pop();
    while(!q.empty()) {
        long long x = q.front();
        ans++;
        long long s = q.size();
        for(int i = 0; i < s; i++) {
            long long y = q.front();
            q.pop();
            if(y % x != 0)
                q.push(y);
        }
    }

    cout << ans << endl;
}