#include <cstdio>
using namespace std;

int main(){
    char str[4];

    scanf("%s", &str);
    for (int i = 0; i < 3; i++){
        if(str[i] == str[i+1]){
            printf("Bad\n");
            return 0;
        }
    }
    printf("Good\n");

    return 0;    
}
