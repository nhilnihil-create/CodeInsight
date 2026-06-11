#include <stdio.h>

int main(){
   int H, A;
   scanf("%d %d", &H, &A);
   int ans = H/A;
   ( H%A == 0 )? printf("%d", ans): printf("%d", ans+1 );

    return 0;
}