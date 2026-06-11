#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1, s2;
    int cnt = 0;
    cin >> s1;
    s2 = s1.substr(s1.size()/2);
    reverse(s2.begin(), s2.end());
    s1 = s1.substr(0, s1.size()/2);
    
    for (int i = 0; i < s1.size(); i++) {
        if (s1.at(i) != s2.at(i)) cnt++;
    }
    
    cout << cnt << endl;
}
