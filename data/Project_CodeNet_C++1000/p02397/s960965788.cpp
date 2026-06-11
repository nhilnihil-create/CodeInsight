#include <stdio.h>

using namespace std;

int main(void)
{
    int x, y, i, temp;
    
    while (true) {
        scanf("%d %d", &x, &y);
        if (!(x | y)) {
            break;
        }
        if (x > y) {
            temp = x;
            x = y;
            y = temp;
        }
        printf("%d %d\n", x, y);
    }
    
    return 0;
}
