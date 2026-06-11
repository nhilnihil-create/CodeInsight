#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        s[i] = (s[i] - 'A' + n) % 26 + 'A';
    }
    cout << s << endl;
    return 0;
}