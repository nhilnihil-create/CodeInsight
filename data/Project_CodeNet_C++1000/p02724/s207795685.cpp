#include <bits/stdc++.h>
using namespace std;

int yen, happiness;

int main () {
    scanf("%d", &yen);
    while (yen > 0) {
        yen-=500;
        if (yen < 0) {
            yen += 500;
            break;
        }
        happiness+=1000;
    }
    while (yen> 0) {
        yen-=5;
        if (yen < 0) {
            yen += 5;
            break;
        }
        happiness+=5;
    }
    
    printf("%d\n", happiness);


    return 0;
}