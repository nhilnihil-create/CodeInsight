#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M1 = 1e18, M2 = 1e9;
ll s, x2, y2, x3, y3;
int main()
{
    cin >> s;
    if(s <= M2){
        printf("0 0 1 0 0 %lld\n",s);
    }
    else if(s % M2 == 0){
        printf("0 0 %lld 1 0 %lld\n", s / M2, M2);
    }
    else{
        x2 = s / M2 + 1;
        y3 = M2;
        x3 = 1;
        y2 = x2 * y3 - s;
        printf("0 0 %lld %lld %lld %lld\n", x2, y2, x3, y3);
    }
    return 0;
}