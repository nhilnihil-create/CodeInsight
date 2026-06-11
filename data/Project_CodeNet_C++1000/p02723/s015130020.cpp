#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int main(){_
    string s;
    cin >> s;
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
    return 0;
}