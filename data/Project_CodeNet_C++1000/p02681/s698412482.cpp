#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    string s1, s2;
    cin >> s1 >> s2;

    string s3 = s2.substr(0, s1.size());
    if(s1 == s3){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}