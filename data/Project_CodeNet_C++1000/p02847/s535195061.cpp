#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

char s[5], t[7][5] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    scanf("%s", s);
    int idx = -1;
    for (int i = 0; i < 7; i++) {
        bool is = true;
        for (int j = 0; j < 3; j++) {
            if (s[j] != t[i][j]) {
                is = false;
                break;
            }
        }
        if (is) {
            idx = i;
            break;
        }
    }
    int cnt = 1;
    for (int i = (idx + 1) % 7, j = 0; j < 7 && i != 0; j++, i = (i + 1) % 7, cnt++);
    printf("%d", cnt);
    return 0;
}
