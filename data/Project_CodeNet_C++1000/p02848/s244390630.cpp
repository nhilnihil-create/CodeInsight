#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    string s;
    vector<char> vec;
    cin >> N >> s;
    
    for (int i = 0; i < s.size(); i++) {
        if (int(s[i]) + N > 90) cout << char(int(s[i]) - 26 + N);
        else cout << char(int(s[i] + N));
    }
    cout << "\n";
}
