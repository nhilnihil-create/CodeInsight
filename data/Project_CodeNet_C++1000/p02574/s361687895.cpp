#include <cstdio>
#include <cstring>
using namespace std;

#define mx 1000006
int A[mx];
bool seen[mx];

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",A+i);
    memset(seen,0,sizeof(seen));

    bool seen_twice=false;

    for(int i=0;i<n;i++){
        if(seen_twice) break;
        int e=A[i];

        for(int f=2;f*f<=e;f++){
            if(e%f==0){
                if(seen[f]){
                    seen_twice=true;
                    break;
                }
                seen[f]=true;
                while(e%f==0) e/=f;
            }
        }

        if(e>1){
            if(seen[e]){
                seen_twice=true;
            }
            seen[e]=true;
        }
    }

    if(!seen_twice){
        printf("pairwise coprime\n");
        return 0;
    }

    int g=A[0];
    for(int i=1;i<n;i++) g=gcd(g,A[i]);

    if(g==1){
        printf("setwise coprime\n");
        return 0;
    }

    printf("not coprime\n");
}
