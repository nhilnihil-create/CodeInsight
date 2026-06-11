#include <bits/stdc++.h>
using namespace std;

#define SIZE_OF_ARRAY(d) (sizeof(d)/sizeof(d[0]))


int main(){
    int a, b;
    cin >> a >> b;
    int d[b];
    int i, sum;
    for (i = 0; i<b; i++){cin >> d[i];}
    sum = accumulate(d, d + SIZE_OF_ARRAY(d), 0);
    if (a < sum){std::cout << -1 << std::endl;}
    else {std::cout << a-sum << std::endl;}
    return 0;
}