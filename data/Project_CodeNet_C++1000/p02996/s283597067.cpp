#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)

const ll mod = 1000000007;

struct info {
    ll cost, limit;
};
bool comp(const info& a, const info& b) {
    return a.limit < b.limit;
}


int main() {
    int n;
    cin >> n;
    vector<info> AB(n);
    rep(i,n) {
        cin >> AB[i].cost >> AB[i].limit;
    }
    sort(AB.begin(), AB.end(), comp);
    ll t = 0;
    rep(i,n) {
        if (t + AB[i].cost <= AB[i].limit) {
            t += AB[i].cost;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}