#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    set<char> t;
    for(int i = 0;i < s.size();i++) t.insert(s.at(i));
    if(t.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}