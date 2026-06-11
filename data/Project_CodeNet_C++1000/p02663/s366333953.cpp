#include <stdio.h>
#include <string.h>

#define ll long long int
#define fl(i,n) for(int i = 0; i < (n); i++)
#define fls(i,s) for(int i = 0; s[i] != '\0'; i++)

int main() {
    int h1,m1,h2,m2,k;
    scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
    int duration;
    if(h1 > h2){
        duration = ((h1-h2)*60) + m1-m2;
    }else if(h2 > h1){
        duration = ((h2-h1)*60) + m2-m1;
    }else{
        if(m1 > m2){
            duration = (m1-m2);
        }else{
            duration = (m2-m1);
        }
    }
    duration -= k;
    printf("%d\n", duration);
    
    return 0;
}
