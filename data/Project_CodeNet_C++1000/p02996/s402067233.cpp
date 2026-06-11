#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int , int> > v(n);
    for (int i = 0 ;i < n ;i++)
        cin >> v[i].first >> v[i].second;


    sort(v.begin() , v.end() , [&](auto &a , auto &b) {
       return a.second < b.second;
    });

    int cur = 0;
    for (int i = 0 ;i < n ;i++) {
        if (cur + v[i].first > v[i].second) {
            cout << "No";
            return 0;
        }
        cur += v[i].first;
    }

    cout << "Yes";
}
