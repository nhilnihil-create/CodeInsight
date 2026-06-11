#include <algorithm>
#include <stack>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

typedef long long Long;
#define whole(xs) xs.begin(), xs.end()

string L;
bool input() {
    getline(cin, L);
    return L != ".";
}

bool Check() {
    stack<char> s;
    for (string::iterator i = L.begin(); i != L.end(); i++) {
        switch (*i) {
            case '(': 
                s.push(*i); 
                break;
            case ')': 
                if (s.empty() || s.top() != '(') return false;
                s.pop();
                break;
            case '[': 
                s.push(*i); 
                break;
            case ']':
                if (s.empty() || s.top() != '[') return false;
                s.pop();
                break;
        }
    }
    return s.empty();
}

void solve() {
    cout << (Check() ? "yes" : "no") << endl;
}

int main() {
    while (input()) solve();
    return 0;
}