#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    string s;
    cin>>s;
    int flag = 0;
    //cout<<s.length()<<endl;
    for (int i = 0; i < s.length(); i += 2) {
        if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D') {
            continue;
        } else {
            flag = 1;
        }
    }

    for (int i = 1; i < s.length(); i += 2) {
        if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D') {
            continue;
        } else {
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
