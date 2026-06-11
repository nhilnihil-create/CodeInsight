#include <cstdio>

int main() {
    int a,b,c;
    std::scanf("%d %d %d",&a,&b,&c);

    if(a < b&&b < c){
        std::printf("Yes\n");
    }
    
    else if(a >= b){
        std::printf("No\n");
    }
    else if(a >= c){
        std::printf("No\n");
    }
    else if(b >= c){
        std::printf("No\n");
    }

return 0;
}
