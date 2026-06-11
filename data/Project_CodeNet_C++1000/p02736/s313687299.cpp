#include <stdio.h>

bool exist = false;
int ans = 0;

int main(void){
    int n = 0;{
        int k;
        while((k = getchar_unlocked() - '0') >= 0) n = 10 * n + k;
    }
    const int m = n - 1;
    for(int i = 0; i < n; ++i){
        switch(getchar_unlocked()){
            case '2':
                exist = true;
                if((m | i) == m) ans ^= 1; 
                break;
            case '3':
                if((m | i) == m) ans ^= 2;
        }
    }
    if(exist) putchar_unlocked((ans & 1) ? '1' : '0');
    else putchar((ans & 2) ? '2' : '0');
    putchar('\n');
    return 0;
}