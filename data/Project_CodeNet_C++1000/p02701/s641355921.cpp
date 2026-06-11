#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    set<string> ans;
    rep(i,n){
        string s;
        cin >> s;
        ans.insert(s);
    }
    cout << ans.size() << endl;
    return 0;
}