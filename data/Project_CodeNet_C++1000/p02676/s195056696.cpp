#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(void){

    int k; cin >> k;
    string s; cin >> s;

    if(s.size() > k){
        rep(i, k){
            cout << s.at(i);
        }
        cout << "...\n";
    } else {
        cout << s << endl;
    }

    return 0;
}