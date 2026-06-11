#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, res = 0, till = 0;
    scanf("%Ld%Ld%Ld", &a, &b, &c);
    while(till < a){
        res += c;
        till += b;
    }
    printf("%Ld\n", res);
    return 0;
}
