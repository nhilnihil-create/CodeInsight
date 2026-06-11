#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    string s, t;
    cin >> s;
    cin >> t;
    int count = 0;
    for(int i = 0; i < 3; i++){
        if(s[i] == t[i]) count += 1;
    }
    cout << count << endl;
    return 0;
}