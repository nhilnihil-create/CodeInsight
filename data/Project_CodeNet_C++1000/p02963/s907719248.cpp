#include <bits/stdc++.h>

using namespace std;

long long s;

void Reverse(long long &x){
    int xx = x;
    x = 0;
    while(xx / 10){
        x = x * 10 + xx % 10;
        xx /= 10;
    }
}
int main(){
    cin >> s;
    if (s > 1e9){
        if (s % 1000000000 == 0){
            printf("0 0 0 1000000000 %d 0", s/1000000000);
            return 0;
        }
        long long x = 1;
        long long temp = s;
        while(temp && x <= 1e10){
            x = x * 10 + temp % 10;
            temp /= 10;
        }
        x /= 10;
        Reverse(x);
        x = 1e9 - x;
        long long x2 = x, y1 = 1;
        long long x1 = 1e9, y2 = (s + x) / 1e9;
        printf("0 0 %lld %lld %lld %lld\n", x1, y1, x2, y2);
    }
    else              
        cout << "0 0 0 " << s << " 1 0" << endl;
    return 0;
}
