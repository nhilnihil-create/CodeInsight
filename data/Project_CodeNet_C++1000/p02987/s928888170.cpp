#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> m(s.size());
    for(int i=0; i<s.size(); i++) m.at(i) = s.at(i);
    sort(m.begin(), m.end());
    
    if(m.at(0) == m.at(1) && m.at(2) == m.at(3) && m.at(1) != m.at(2)) puts("Yes");
    else puts("No");
}