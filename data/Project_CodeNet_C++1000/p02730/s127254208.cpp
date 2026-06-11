#include <bits/stdc++.h>
using namespace std;
int bunbun(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    string S;
    cin >> S;
    int N = S.size();

    bool a = true;

    //case 1
    if (!bunbun(S)) a = false;
    //case 2
    if (!bunbun(S.substr(0, S.size() / 2))) a = false;

    cout << (a ? "Yes" : "No") << endl;
}