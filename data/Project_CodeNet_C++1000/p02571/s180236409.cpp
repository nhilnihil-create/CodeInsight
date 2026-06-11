#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
typedef long long ll;
using namespace std;

int inf = 1000001;

int main() {
    string s, t; cin >> s >> t;
    int cnt = inf;
    int len = s.size() - t.size();
    for (int i = 0; i <= len; ++i) {
        int temp = 0;
        for (int j = i, k = 0; j < s.size() && k < t.size(); j++, k++) {
            if (t[k] != s[j]) {
                temp++;
            }
        }
        
       // cout << "temp " << temp << endl;
        cnt = min(cnt, temp);
        //cout << "cnt " << cnt << endl;
        
    }
    cout << cnt << endl;
    return 0;
}
