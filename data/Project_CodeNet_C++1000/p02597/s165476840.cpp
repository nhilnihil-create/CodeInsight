#include <iostream>
#include <string>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int red = 0;
    for(auto x: s)
        if(x == 'R') red++;

    int ans = 0;
    for(int i = 0; i < red; i++)
        if(s[i] != 'R') ans++;
    cout << ans;
}
