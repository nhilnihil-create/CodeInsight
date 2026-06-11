#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

int next(int a, int L) {
    stringstream ss;
    ss<<a;
    string s = ss.str();
    s = string(L-s.length(), '0') + s;
    sort(s.begin(), s.end());
    int m = atoi(s.c_str());
    reverse(s.begin(), s.end());
    int mm = atoi(s.c_str());
    return mm - m;
}

int main() {
    int a, L;
    while(cin>>a>>L, a|L) {
        map<int, int> m; m[a] = 0;
        for (int j=1; ; j++) {
            int p = next(a, L);
            if (m.find(p) != m.end()) {
                cout<<m[p]<<" "<<p<<" "<<j-m[p]<<endl;
                break;
            }
            m[p] = j;
            a = p;
        }
    }
}