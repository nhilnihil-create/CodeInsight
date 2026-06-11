#include <bits/stdc++.h>

using namespace std;


signed main(){
    vector<string> s = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string t;
    cin >> t;
    cout << 7 - distance(s.begin(), find(s.begin(), s.end(), t)) << endl;

}
