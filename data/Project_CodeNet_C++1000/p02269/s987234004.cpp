#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

#define rep(i, N) for (int i = 0; i < N; ++i)

static const char *INSERT = "insert";
static const char *FIND = "find";

int main() {
    int n, strMax = 12;
    scanf("%d", &n);
    char action[strMax], key[strMax];

    map<string, bool> data;
    rep(i, n) {
        scanf("%s %s", action, key);
        if (strcmp(INSERT, action) == 0) {
            data[key] = true;
        } else if (strcmp(FIND, action) == 0) {
            if (data[key]) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}
