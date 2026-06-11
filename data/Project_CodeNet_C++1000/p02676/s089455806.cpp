#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
typedef long long ll;
using namespace std;
unsigned long long x = 1e18;

int main() {
    int k; cin >> k;
    string s; cin >> s;
    if (s.size() <= k)
        cout << s << endl;
    else {
        for (int i = 0; i < k; ++i) {
            cout << s[i];
        }
        cout << "...";
    }
    
    return 0;
}
