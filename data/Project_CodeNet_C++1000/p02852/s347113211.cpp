#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
template <typename F, typename S> std::ostream& operator<<(ostream& os, const pair<F,S>& p) {
    os << "(" << p.first << "," << p.second << ")"; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["; for(const T& a: v){ os << a << ", "; } os << "]"; return os; }
template <typename K, typename V> ostream& operator<<(ostream& os, const map<K,V>& m) {
    os << "{"; for(const auto& p: m){ os << p.first <<":"<< p.second << ", "; } os << "}"; return os; }

vector<LL> solve(LL n, LL m, string s){
    vector<LL> ans;
    LL cur = n;
    while(cur > 0){
        LL v = 0;
        for(LL i = 1; i <= m; ++i){
            if(cur - i < 0) break;
            if(s[cur-i] == '0'){
                v = i;
            }
        }
        if(v == 0) return vector<LL>{-1};
        ans.push_back(v);
        cur -= v;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    LL n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<LL> ans = solve(n, m, s);
    for(LL i = 0; i < ans.size(); ++i){
        if(i+1 == ans.size()){
            cout << ans[i] << endl;
        }else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}

