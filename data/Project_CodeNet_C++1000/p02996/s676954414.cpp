#include<bits/stdc++.h>
using namespace std;

#define LL long long

bool cmp(pair<int,int>a, pair<int,int>b) {return a.first < b.first;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x, y; cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({y, x});
    }   

    sort(v.begin(), v.end(), cmp);

    LL cur = 0;
    for(int i = 0; i < n; i++) {
        cur += v[i].second;
        if(cur > v[i].first) return cout << "No", 0;
    }
    cout << "Yes";
}