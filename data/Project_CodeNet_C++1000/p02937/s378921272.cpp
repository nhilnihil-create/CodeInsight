#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    string s, t; cin >> s >> t;
    long long l = s.length();
    vector<set<int> > p(26);
    for (int i = 0; i < l; i++) 
        p[s[i]-'a'].insert(i);
    
    for (int i = 0; i < t.length(); i++) {
        if (p[t[i]-'a'].empty()) {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    long long cnt = 0, j = 0;
    while (j < t.length()) {
        int k = -1;
        while (j < t.length() && p[t[j]-'a'].upper_bound(k) != p[t[j]-'a'].end()) {
            k = *p[t[j]-'a'].upper_bound(k);
            j++;
        }
        if (j >= t.length()) {
            cout << cnt * l + k + 1<< endl;
            return 0;
        }
        cnt++;
    }

}