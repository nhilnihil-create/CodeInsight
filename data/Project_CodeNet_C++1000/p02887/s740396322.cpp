#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int num = 0;
    char c = '*';
    for(int i=0; i<n; i++){
        if(c == s[i]) continue;

        num++;
        c = s[i];
    }
    cout << num << endl;
}