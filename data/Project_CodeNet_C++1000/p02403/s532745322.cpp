#include <cstdio>
using namespace std;

int main(){
    int H, W;
    while(true){
        scanf("%d %d", &H, &W);
        if(H == 0 && W == 0) break;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                printf("%c", '#');
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}