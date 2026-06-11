#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char stT[110], stH[110];
    int result;
    int ptT=0, ptH=0;
    
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%s %s", stT, stH);
        result = strcmp(stT, stH);
        if (result > 0) ptT+=3;
        else if (result <0) ptH += 3;
        else ptT++, ptH++;
    }
    printf("%d %d\n", ptT, ptH);
    return 0;
}