#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n, x;
    while(true){
        scanf("%d %d\n", &n, &x);
        if(n == 0 && x == 0) break;
        int cnt = 0;
        for(int i = n; i > x / 3; i--){
            for(int j = i - 1; j > (x-i)/2; j--){
                if(x - (i + j) > 0) cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
