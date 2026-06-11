#include <stdio.h>

int main() {
    int h, a;
    scanf("%d %d",&h ,&a);
    int divide = h/a;
	h%a ==0 ? printf("%d\n",divide) : printf("%d\n",divide+1);
     
    return 0;
}