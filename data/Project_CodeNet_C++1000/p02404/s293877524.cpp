#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    for (;;) {
        scanf("%d %d",&h,&w);
        if (h==0) break;
        for (int i=0;i<w;i++) printf("#");
        printf("\n");
        for (int j=0;j<h-2;j++) {
            for (int i=0;i<w;i++) {
                printf("%c",(i==0 || i==w-1)?'#':'.');
            }
            printf("\n");
        }
        for (int i=0;i<w;i++) printf("#");
        printf("\n\n");
    }
    return 0;
}

