#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
using namespace std;

int main() {
    double n, s[1001];
    
    while (1) {
        double ave = 0, bunsan = 0;
        scanf("%lf", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &s[i]);
            ave = ave + s[i];
        }
        ave = ave / n;


        for (int i = 0; i < n; i++) {
            bunsan = bunsan + ((s[i] - ave)*(s[i] - ave));
        }
        bunsan = sqrt(bunsan / n);

        printf("%f\n", bunsan);
    }


    return 0;
}