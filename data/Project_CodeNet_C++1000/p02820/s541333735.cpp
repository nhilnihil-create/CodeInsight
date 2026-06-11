#include <iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;
using lli = long long int;

void deleteD(vector<char>& cv) {
    vector<char>::iterator p = cv.begin();
    char prev = 'a';
    while (p != cv.end()) {
        if (prev == *p) {
            p = cv.erase(p);
            prev = 'a';
        }
        else {
            prev = *p;
            p++;
        }
    }
}

int main() {
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;
    vector<char> kv;
    vector<vector<char>> allv(k, kv);
    for (int i = 0; i < n; i++) {
        allv[i % k].push_back(t[i]);
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        deleteD(allv[i]);
        for (int j = 0; j < allv[i].size(); j++) {
            switch (allv[i].at(j)) {
            case'r':
                res += p;
                break;
            case's':
                res += r;
                break;
            case'p':
                res += s;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}