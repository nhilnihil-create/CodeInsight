#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0;i<s.size();i++){
        if(s[i] + n > 'Z') s[i] = s[i] + n -26;
        else s[i] += n;
    }
    cout << s << endl;
}