#include <cstdio>
using namespace std;
int main() {
    char c;
    const char a = 'a';
    int cnt[26];
    for (int i = 0; i < 26; i++)
        cnt[i] = 0;
    while ((c = getchar()) != EOF) {
        if (65 <= c && c <= 90) {
            c += 32;
            cnt[c-a]++;
        }
        else if (97 <= c && c <= 122) {
            cnt[c-a]++;
        }
    }
    for (int i = 0; i < 26; i++)
        printf("%c : %d\n", a+i, cnt[i]);
}