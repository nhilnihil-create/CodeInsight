#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cassert>
// using namespace std;
// #define int long long
#define REP(i,s,n) for (int i = (s); i < (n); ++i)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) for (int i = n; i >= 0; i--)
#define INF (int)(1e9+7)
#define space " "
#define ENDL "\n"
#define MAXL 100

int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

inline void init() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
}
// ??¢?????¬??????????????????????????????????????????!!
inline void nextInt(int *a) { scanf("%d", a); }
inline void nextInt(int *a, int *b) { scanf("%d %d", a, b); }
inline void nextInt(int *a, int *b, int *c) { scanf("%d %d %d", a, b, c); }
inline void nextDouble(double *a) { scanf("%lf", a); }
inline void nextDouble(double *a, double *b) { scanf("%lf %lf", a, b); }
inline void nextDouble(double *a, double *b, double *c) { scanf("%lf %lf %lf", a, b, c); }
inline void nextLine(char *c) { scanf("%s", c); getchar();/*?????????????????¨???*/ }
inline std::string nextLine() {
    std::string s = ""; char str[MAXL+1];
    scanf("%s", str); getchar(); /*?????????????????¨???*/
    return s += str;
}
inline void print(double *a, int n = 0) {
    std::cout << std::fixed << std::setprecision(n) << *a << ENDL;
}
inline void print(int a) {
    printf("%d\n", a);
}

/************************End of template*************************/

int main() {
    std::string s;
    bool flag = true;
    std::stack<char> st, ini;

    init();

    while (true) {
        s = "";
        st = ini;
        flag = true;
        std::getline(std::cin, s);
        //std::cout << "[" << s << "]" << ENDL;
        if (s[0] == '.') break;

        rep(i,s.size()) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    flag = false;
                    break;
                } else if (st.top() == '(') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if (s[i] == ']') {
                if (st.empty()) {
                    flag = false;
                    break;
                } else if (st.top() == '[') {
                    st.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (!st.empty()) flag = false;
        if (flag) std::cout << "yes" << ENDL;
        else std::cout << "no" << ENDL;
    }

    return 0;
}