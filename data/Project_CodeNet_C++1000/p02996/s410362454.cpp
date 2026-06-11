#include <bits/stdc++.h>
#define rep(s,t) for (int s = 0; s < t; s++);
using namespace std;
using ll = long long;


int main() {
    int n, a, b; cin >> n;

    vector<pair<int, int>> v;

    for ( int i = 0; i < n; i++){
        cin >> a >> b;
        v.emplace_back(b, a);
    }

    sort(v.begin(), v.end());

    int sum = 0;

    bool isYes = true;

    for (auto t : v){
        sum += t.second;

        if (sum > t.first){
            isYes = false;
            break;
        }
    }

    cout << (isYes ? "Yes" : "No") << endl;
}