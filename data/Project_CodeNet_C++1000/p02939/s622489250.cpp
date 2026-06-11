#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    string las;
    int ans = 0;
    string cur;
    for(auto &i : s){
        cur += i;
        if(cur == las) continue;
        ans++;
        las = cur;
        cur = "";
    }
    cout << ans << endl;
}
