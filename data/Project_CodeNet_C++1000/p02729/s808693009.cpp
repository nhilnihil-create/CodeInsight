#include <stdio.h>
#include <string.h>

#define ll long long int
#define fl(i,a,n) for(int i = a; i < (n); i++)
#define fls(i,a,s) for(int i = a; s[i] != '\0'; i++)

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int ctr = 0;
    fl(i,0,n){
        fl(j,i+1,n){
            ctr++;
        }
    }
    fl(i,0,m){
        fl(j,i+1,m){
            ctr++;
        }
    }
    printf("%d\n", ctr);
    
    return 0;
}
