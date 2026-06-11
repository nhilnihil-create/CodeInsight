#include <stdio.h>
#include <string.h>

int main()
{
    int health, attack, attemp = 0;
    scanf("%d %d", &health, &attack);

    while(health > 0)
    {
        health -= attack;
        attemp++;
    }

    printf("%d", attemp);

    return 0;
}