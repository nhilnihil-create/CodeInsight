#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

const int N_MAX = 3010;



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A;
    int sum = 0;
    rp(i, 0, n) {
        int a;
        scanf("%d", &a);
        sum += a;
        A.emplace_back(a);
    }
    vector<int> d;
    for(int i = 1; i * i <= sum; i++) {
        if(sum%i == 0) {
            d.emplace_back(i);
            if(i != sum/i) d.emplace_back(sum/i);
        }
    }

    sort(d.rbegin(), d.rend());
    for(auto x: d) {
        int cnt = 0;
        priority_queue<int> q;
        rp(i, 0, n) {
            cnt += A[i]%x;
            q.push(A[i]%x);
        }
        int s = cnt / x;
        rp(i, 0, s) {
            cnt -= q.top(); q.pop();
        }
        if(cnt <= k) {
            cout << x << endl;
            return 0;
        }
    }
}
