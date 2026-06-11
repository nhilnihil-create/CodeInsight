#include <stdio.h>

int main(void)
{
    int a[10];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        bool ans = false;
        for (int i = 0; i < 10; i++){
            scanf("%d", a + i);
        }
        for (int i = 0; i < (1 << 10); i++){
            int stack[2];
            int j;
            stack[0] = stack[1] = 0;
            for (j = 0; j < 10; j++){
                int k = ((i >> j) & 1);
                if (stack[k] < a[j]){
                    stack[k] = a[j];
                }
                else {
                    break;
                }
            }
            if (j == 10){
                ans = true;
                break;
            }
        }
        puts(ans ? "YES" : "NO");
    }

    return (0);
}