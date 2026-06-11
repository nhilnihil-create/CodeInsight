#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    map<string,string> m;
    m["Sunny"] = "Cloudy";
    m["Cloudy"] = "Rainy";
    m["Rainy"] = "Sunny";
    cout << m.at(s) << endl;
}