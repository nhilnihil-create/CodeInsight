#include<bits/stdc++.h>
using namespace std;
string s, t;
int main(){
    cin >> s >> t;
    int answer = 0;
    for(int i = 0; i < s.size(); i++)
        answer += s[i] != t[i];
    cout << answer << endl;
    return 0;
}