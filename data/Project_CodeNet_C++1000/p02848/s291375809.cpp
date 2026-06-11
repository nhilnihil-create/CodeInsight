#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;string s;
    cin >> n >> s;
    rep(i,s.size()){
        if((int)s.at(i) + n <= 90) s.at(i) += n;
        else s.at(i) = 64 + ((int)s.at(i) + n - 90);
    }
    cout << s << endl;
}