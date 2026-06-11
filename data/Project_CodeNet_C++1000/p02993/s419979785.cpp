#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    string s;
    cin >> s;
    if(s.at(0) == s.at(1) || s.at(1) == s.at(2) || s.at(2) == s.at(3)) cout << "Bad" << endl;
    else cout << "Good" << endl;
}