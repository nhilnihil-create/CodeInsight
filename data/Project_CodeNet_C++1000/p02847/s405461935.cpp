#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    vector<string> days = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int ans = 7;
    for(string s : days) {
        if(s == S)
            break;
        else
            ans--;
    }
    cout << ans << endl;
}