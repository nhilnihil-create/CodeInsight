#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
 
int main()
{
    int n; cin >> n; vector<int> a(n); for(int i = 0; i < n; i++)cin >> a[i]; sort(a.begin(), a.end());
 
    int cur = a.front();
    vector<pair<int,int>> rs;
 
    for(int i = 1; i < n - 1; i++) {
        if(a[i] >= 0) {
            rs.emplace_back(cur, a[i]);
            cur -= a[i];
        }
    }
    rs.emplace_back(a.back(), cur);
    cur = a.back() - cur;
 
    for(int i = 1; i < n - 1; i++) {
        if(a[i] < 0) {
            rs.emplace_back(cur, a[i]);
            cur -= a[i];
        }
    }
    cout << cur << endl;
    for(auto i : rs)cout << i.first << " " << i.second << endl;
}