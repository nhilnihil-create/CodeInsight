#include <bits/stdc++.h>
using namespace std;
int main(){
    string s, t;
    int changes = 10000;
    getline(cin, s);
    getline(cin, t);
    int count = s.length() - t.length() + 1;
    //cout << count << endl;
    for (int i = 0; i < count; ++i){
        int a = i;
        int c = 0;
        for (int j = 0; j < t.length(); ++j){
            if (s[a] != t[j]){
                c++;
            }
            a++;
        }
        //cout << c << endl;
        changes = min(changes, c);
        //cout << changes << endl;
    }
    cout << changes;
}