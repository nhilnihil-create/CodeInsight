#include <stdio.h>
int main() {
    int hoge = 0, ahoge = 0, fuga = 0;
    scanf("%d %d %d", &hoge, &ahoge, &fuga);
    printf("%s\n", hoge < ahoge && ahoge < fuga ? "Yes" : "No");
    return 0;
}

