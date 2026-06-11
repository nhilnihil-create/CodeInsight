#include <iostream>
#include <string>
#define max(a, b) ((a) < (b) ? (b) : (a))
using namespace std;
int n;
string s = "a";
void dfs(char a) {
    if (s.size() == n) {
        cout << s << endl;
        return;
    }
    for (char c = 'a'; c <= a + 1; c++) {
        s += c;
        dfs(max(c, a));
        s.erase(s.end() - 1);
    }
}
int main() {
    while (cin >> n) {
        dfs('a');
    }
    return 0;
}