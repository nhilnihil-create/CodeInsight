#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int count = 0;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != t[i])
            count++;
    }
    cout << count << "\n";

    return 0;
}
