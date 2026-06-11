#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;  cin >> n;
    string c[] = {"AC", "WA", "TLE", "RE"};
    map<string , int> mp;
    for (int i = 0; i < n; i++) {
        string s;   cin >> s;
        mp[s]++;
    }
    for (int i = 0; i < 4; i++)
        cout << c[i] << " x " << mp[c[i]] << endl;

    return 0;
}