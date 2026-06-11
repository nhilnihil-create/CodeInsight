#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> s(n);
    rep(i,n) {
        int a;
        cin >> a;
        s[i] = pair<int,int>(a,i+1);
    }
    sort(s.begin(),s.end());
    rep(i,n) cout << s[i].second << " ";

    return 0;
}
