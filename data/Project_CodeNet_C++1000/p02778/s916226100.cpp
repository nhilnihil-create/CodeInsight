#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin >> s;
    string ans={};
    rep(i, s.size()){
        ans.push_back('x');
    }
    cout << ans << endl;
}