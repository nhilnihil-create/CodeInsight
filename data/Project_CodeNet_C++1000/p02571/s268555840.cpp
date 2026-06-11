#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s, t;
    cin >> s >> t;
    
    int n = (int)(s.size() - t.size());
    int min = 1000;
    
    for (int i = 0; i <= n; i++) {
        int counter = 0;
        for (int j = 0; j < t.size(); j++) {
            if (s.at(i+j) != t.at(j)) {
                counter++;
            }
        }
        if (counter < min) {
            min = counter;
        }
    }
    cout << min <<endl;
    return 0;
}