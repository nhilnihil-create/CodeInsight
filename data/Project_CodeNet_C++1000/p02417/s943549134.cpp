#include<cstdio>

int main() {
    char ch;
    int cnt[26] = {};

    while (scanf("%c", &ch) != EOF) {
        if (ch > 'Z') ch -= ('a' - 'A');
        cnt[ch - 'A']++;            
    }
    for (int i = 0; i < 26; i++) printf("%c : %d\n", 'a' + i, cnt[i]);

    return 0;
}