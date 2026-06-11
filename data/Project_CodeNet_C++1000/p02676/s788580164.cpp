#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    string s;
    cin >> k >> s;
    if( s.size() > k) {
        for(int i=0; i<k; i++) {
            cout << s[i];
        }
        cout << "...";
        cout << endl;
        return 0;
    }
    else {
        for(int i=0; i<s.size() ; ++i) {
            cout << s[i];
        }
        cout << endl;
        return 0;
    }
}