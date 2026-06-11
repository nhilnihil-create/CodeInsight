#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    string s;
    cin >> s;
    
    vector<string> week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    
    rep(i,7) {
        if(s == week[i])
            cout << 7-i << endl;
    }
    
    
    return 0;
}
