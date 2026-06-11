#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string s, t;
    int res = 1000;
    
    cin >> s >> t;
    
    for(int i = 0; i <= s.size() - t.size(); i++) {
        int temp = 0;
        for(int j = 0; j < t.size(); j++)
            temp += (s[i + j] != t[j]);
        res = min(res, temp);
    }
    
    cout << res;
    
    return 0;
}
