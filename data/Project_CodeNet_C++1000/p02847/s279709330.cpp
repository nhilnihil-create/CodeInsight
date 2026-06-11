#include <iostream>
#include <map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    string s;
    cin >> s;
    map<string, int> m;
    m["SUN"] = 7;
    m["MON"] = 6;
    m["TUE"] = 5;
    m["WED"] = 4;
    m["THU"] = 3;
    m["FRI"] = 2;
    m["SAT"] = 1;
    cout << m[s] << endl;
    return 0;
}
