#include <stdio.h>

int main()
{
    int monster;
    int attack;

    scanf("%d %d", &monster, &attack);

    (monster % attack > 0) ? printf("%d", (monster / attack) + 1) : printf("%d", (monster / attack));

    return 0;
}