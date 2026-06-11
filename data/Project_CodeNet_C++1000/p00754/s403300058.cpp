#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000

typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main(void) {
    string str;
    while (1) {
        str.clear();
        getline(cin, str);
        if (str == ".") break;
        stack<char> st;
        int i;
        for (i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[') st.push(str[i]);
            else if (str[i] == ')') {
                if (st.empty() || st.top() != '(') break;
                st.pop();
            } else if (str[i] == ']') {
                if (st.empty() || st.top() != '[') break;
                st.pop();
            }
        }
        if (i == str.size() && st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}