#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    long long l, r;
    cin >> l >> r;

    int mod_min = 2018;

    r = min(r, l + 2019);

    for(long long i = l; i < r; i++){
        for(long long j = i + 1; j <= r; j++){
            int mod = (i * j) % 2019;

            mod_min = min(mod_min, mod);
        }
    }

    printf("%d\n",mod_min);
    return 0;

}
