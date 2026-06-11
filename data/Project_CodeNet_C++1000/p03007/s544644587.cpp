#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int>> ans;
    multiset<int> a;
    rep(i,n) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int min_num = *a.begin();
    a.erase(a.begin());
    auto k = a.end();k--;
    int max_num = *k;
    a.erase(k);
    for(auto i = a.begin(); i != a.end(); i++){
        int num = (*i);
        if(num <= 0) {
            ans.push_back(make_pair(max_num, num));
            max_num -= num;
        } else {
            ans.push_back(make_pair(min_num, num));
            min_num -= num;
        }
    }
    ans.push_back(make_pair(max_num, min_num));
    cout << max_num - min_num << endl;
    for (auto i: ans) {
        cout << i.first <<" " << i.second << endl;
    }
}
