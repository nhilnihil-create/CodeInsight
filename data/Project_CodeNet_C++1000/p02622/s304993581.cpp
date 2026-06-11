#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s,t;
    cin >> s >> t;
    int ans = 0;
    rep(i,s.size()){
        if(s[i] != t[i]) ans++;
    }
    cout << ans << endl;
}