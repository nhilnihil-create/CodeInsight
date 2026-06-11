#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    scanf("%d", &a);
    switch (a % 10){
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
        printf("hon");
        break;
    case 0:
    case 1:
    case 6:
    case 8:
        printf("pon");
        break;
    case 3:
        printf("bon");
        break;
    }
}
