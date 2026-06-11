#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,k,r,s,p;
    scanf("%d %d", &n, &k);
    scanf("%d %d %d", &r, &s, &p);
    char t[n];
    scanf("%s", t);
    int nPoint = 0;  
/*    for(int i = 0; i < n; i++){
        if(t[i] == 'r'){
            nPoint += p;
        }
        if(t[i] == 's'){
            nPoint += r;
        }
        if(t[i] == 'p'){
            nPoint += s;
        }
    }*/
    
    for(int i = 0; i < k; i++){
        bool bCanWin = true;
        for(int j = 0; j * k + i < n; j++){
            if(!bCanWin){
                bCanWin = true;
                continue;
            }
            if(j * k + k + i < n){
                if(bCanWin && t[j * k + i] == t[j * k + k + i]){
                    bCanWin = false;
                }
            }
            if(t[j * k + i] == 'r'){
                nPoint += p;
            }
            if(t[j * k + i] == 's'){
                nPoint += r;
            }
            if(t[j * k + i] == 'p'){
               nPoint += s;
            }
        }
    }
    printf("%d", nPoint);
    return 0;
}
