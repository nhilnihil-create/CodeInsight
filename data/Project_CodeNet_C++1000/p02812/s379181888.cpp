#include <iostream>
#include <string>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    int n, ans=0;
    string s, t="ABC";
    cin >> n >> s;

    rep(i, n){
        if(s.substr(i, 3)==t) ans++;
    }

    cout << ans << endl;

    return 0;
}