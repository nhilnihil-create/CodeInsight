#include <stdio.h>

int main() {
int aa;
char bb[aa];
scanf("%d %s", &aa, bb);
if (aa%2 != 0){
    printf("No");
    return 0;
}
for(int j=0; j<aa/2; j++){
    if(bb[j] != bb[aa / 2 +j]){
        printf("No");
        return 0;
    }
}
printf("Yes");



    return 0;
}