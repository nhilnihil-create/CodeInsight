#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    string ans = "Yes";
    rep(i,s.size()){
        if(i%2==0 && s.at(i) == 'L'){
            ans ="No";
            break;
        }
        else if(i%2==1 && s.at(i) == 'R'){
            ans ="No";
            break;
        }
    }
    cout << ans << endl;
}