#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x,t;
    set<int> s;
    cin >> x >> n;
    for(int i = 0; i < n; ++i){
        cin >> t;
        s.insert(t);
    }

    vector<pair<int,int>> diff;
    for(int i = -200; i <= 200; ++i){
        if(s.count(i)) continue;
        diff.emplace_back(abs(x-i),i);
    }
    sort(diff.begin(),diff.end());
    int mn = 2e9;
    for(int i = 0; i < diff.size(); ++i){
        if(diff[i].first!=diff[0].first) break;
        mn = min(diff[i].second,mn);
    }
    cout << mn;
    return 0;
}