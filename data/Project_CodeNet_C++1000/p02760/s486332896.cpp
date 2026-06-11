#include <stdio.h>

int main() {
    int bingos[3][3] = {0};
    bool bingos_mark[3][3] = {false};
    int ninp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &bingos[i][j]);
        }
    }
    scanf("%d", &ninp);
    for (int i = 0; i < ninp; i++) {
        int te;
        scanf("%d", &te);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (te == bingos[i][j]) {
                    bingos_mark[i][j] = true;
                }
            }
        }
    }

    if (bingos_mark[0][0] && bingos_mark[1][1] && bingos_mark[2][2]) {
        printf("Yes");
    } else if (bingos_mark[0][2] && bingos_mark[1][1] && bingos_mark[2][0]) {
        printf("Yes");
    } else if (bingos_mark[0][0] && bingos_mark[0][1] && bingos_mark[0][2]) {
        printf("Yes");
    } else if (bingos_mark[1][0] && bingos_mark[1][1] && bingos_mark[1][2]) {
        printf("Yes");
    } else if (bingos_mark[2][0] && bingos_mark[2][1] && bingos_mark[2][2]) {
        printf("Yes");
    } else if (bingos_mark[0][0] && bingos_mark[1][0] && bingos_mark[2][0]) {
        printf("Yes");
    } else if (bingos_mark[0][1] && bingos_mark[1][1] && bingos_mark[2][1]) {
        printf("Yes");
    } else if (bingos_mark[0][2] && bingos_mark[1][2] && bingos_mark[2][2]) {
        printf("Yes");
    } else {
        printf("No");
    }
}