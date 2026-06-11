#include <bits/stdc++.h>
using namespace std;




























int main () {
    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<char> c(N);
    for (int i = 0; i < N; i++) {
        c[i] = s[i];
    }
    
    int result = 0;
    while (c.size()) {
        for (int i = 0; c.size() != 0 && c[i] == 'R';){
            c.erase(c.begin());
        }
        for (int i = c.size() - 1; c.size() != 0 && c[i] == 'W'; i--) {
            c.pop_back();
        }

        if (c.size() == 0) {
            break;
        }
        else {
            c.erase(c.begin());
            if (c.size() != 0) c.pop_back();
            result++;
        }
    }

    cout << result << endl;
}