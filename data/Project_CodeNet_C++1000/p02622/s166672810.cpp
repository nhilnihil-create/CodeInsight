#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main() {
    string s, t;
    cin >> s >> t;
    int sum = 0;
    rep(i, s.length()){
        if(s[i] != t[i]) ++sum;
    }
    cout << sum << endl;
}

