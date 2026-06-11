#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}
 
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> a(m);
    set<int> ac;
    vector<int> wa(n);
    for(auto &p : a ) cin >> p.first >> p.second;
    for(auto &p : a) {
        if(p.second == "AC") ac.insert(p.first);
        else if (!ac.count(p.first)) wa[p.first - 1]++;
        else continue;
    }
    int pena = 0;
    rep(i, n) {
        if(ac.count(i + 1)) pena += wa[i];
    }
    cout << ac.size() << ' ' << pena << endl;
}