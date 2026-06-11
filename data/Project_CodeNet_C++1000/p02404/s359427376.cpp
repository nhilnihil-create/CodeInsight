#include <cstdio>
using namespace std;

int main(){
    int H, W;
    while(true){
        scanf("%d %d", &H, &W);
        if(H == 0 && W == 0) break;
        for(int i = 0; i < H; i++){
            printf("%c", '#');
            for(int j =0; j < W - 2; j++){
                if(i == 0 || i == H - 1) printf("%c", '#');
                else printf("%c", '.');
            } 
            printf("%c\n", '#');
        }
        printf("\n");
    }
    return 0;
}