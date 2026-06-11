#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int r;
    scanf("%d", &r);
    printf("%.10f\n", 2 * r * acos(-1.0));
    return 0;
}
