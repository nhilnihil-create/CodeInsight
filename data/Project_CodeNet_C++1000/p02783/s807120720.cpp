#include<stdio.h>
int main(){
    int health, damage;
    scanf("%d %d", &health, &damage); 
    int attack = health/ damage;
    health % damage == 0 ? printf("%d\n",attack) : printf("%d\n",++attack);
    return 0;
}