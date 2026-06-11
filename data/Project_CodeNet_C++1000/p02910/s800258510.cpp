#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <string>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    bool t = true;
    for(int i=0; i<s.size(); i++) {
        if (i % 2 == 0) {
            if (s.substr(i, 1) == "R" || s.substr(i, 1) == "U" || s.substr(i, 1) == "D") {
                continue;
            } else {
                t = false;
                break;
            }
        } else {
            if (s.substr(i, 1) == "L" || s.substr(i, 1) == "U" || s.substr(i, 1) == "D") {
                continue;
            } else {
                t = false;
                break;
            }
        }
    }
    if(t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}