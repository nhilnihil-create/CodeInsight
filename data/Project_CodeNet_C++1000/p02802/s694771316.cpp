#include <bits/stdc++.h>
#include <limits.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n, m;
    cin >> n >> m;
    vector<int> ac(n);
    vector<int> wa(n);
    int p;
    string s;
    int ansa = 0;
    rep(i, m) {
        cin >> p >> s;
        if(!ac[p-1]) {
            if(s == "AC") {
                ansa++;
                ac[p-1] = 1;
            } else if(s=="WA"){
                wa[p-1]++;
            }
        }
    }

    int answ = 0;
    rep(i,n){
        if(ac[i]){
            answ += wa[i];
        }
    }

    cout << ansa << " " << answ << endl;
}