#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    vector<char> s(6);
    rep(i, 6){
        cin >> s.at(i);
    }
    if(s.at(2) == s.at(3) && s.at(4) == s.at(5)){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}