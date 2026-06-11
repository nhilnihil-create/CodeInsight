#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    printf("%d", (n * n - n + m * m - m) / 2);
    
    return 0;
}
