#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    vector<string> d = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int day;
    rep(i, 7) {
        if(d[i] == s){
            day = 7 - i;
        }
    }
    cout << day << endl;
    return 0;
}