#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
 
#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
const int INF = 1e9;
 
using namespace std;
 
int main() {
    stringstream result;
    while(1) {
        string str;
        int m;
        cin >> str;
        if (str == "-")
            break;
        cin >> m;
        int h = 0;
        REP(i, m) {
            cin >> h;
            str += str.substr(0, h);
            str.erase(0, h);
        }
        result << str << endl;
    }
    cout << result.str();
    return 0;
}