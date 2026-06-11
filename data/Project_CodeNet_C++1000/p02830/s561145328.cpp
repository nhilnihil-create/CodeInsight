#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;string s,t;
    cin >> n >> s >> t;
    rep(i,n){
        cout << s.at(i) << t.at(i);
    }
    cout << endl;
}