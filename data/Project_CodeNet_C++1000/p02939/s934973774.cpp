#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int l,ans = 0;
    string s;
    string k = "", t = "";
    cin >> s;
    rep(i,s.length()){
        k.push_back(s[i]);
        if (k != t){
            t = k;
            k = "";
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}