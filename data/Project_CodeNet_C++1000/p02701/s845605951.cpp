#include <set>
#include <stdio.h>
using namespace std;
char s[15];
set<string> st;
int main() {
    int n, r = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (st.find(s) != st.end()) continue;
        st.insert(s);
        r++;
    }
    printf("%d\n", r);
    return 0;
}
