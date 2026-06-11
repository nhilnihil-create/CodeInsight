#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int dig(int n) {
    int ans = 0;
    if(n == 0) return 1;
    while(n != 0) {
        n/=10;
        ans++;
    }
    return ans;
}
int pow10(int n) {
    static vector<int> ans(1,1);
    while(ans.size()-1 < n) {
        ans.push_back(ans.back()*10);
    }
    return ans[n];
}

int lowest_num(int n) {
    return n%10;
}
int highest_num(int n) {
    return n/pow10(dig(n)-1);
}

int main(){
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> s(10, vector<int>(10,0));
    for(int a = 1; a <= n; a++) {
        s[highest_num(a)][lowest_num(a)]++;
    }
    int ans = 0;
    for(int l = 1; l <= 9; l++) for(int h = 1; h <= 9; h++) {
        ans += s[l][h] * s[h][l];
    }
    cout << ans << endl;
}