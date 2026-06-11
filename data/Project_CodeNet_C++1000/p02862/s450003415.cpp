#include <iostream>
using namespace std;
const long long p = 1000000007;

long long powmod(long long b, long long e){
    long long t = 1;
    while(e){
        if (e & 1) t = (t * b) % p;
        b = (b * b) % p;
        e >>= 1;
    }
    return t;
}

int main(){
    int x, y, z;
    cin >> x >> y;
    z = x + y;
    if (z % 3) cout << 0 << '\n';
    else{
        z /= 3;
        x -= z;
        y -= z;
        if ((x < 0) || (y < 0)) cout << 0 << '\n';
        else if ((x == 0) || (y == 0)) cout << 1 << '\n';
        else{
            long long fact = 1, factx, facty;

            for (long long i = 1; i <= x + y; i++){
                fact = (fact * i) % p;
                if (i == x) factx = fact;
                if (i == y) facty = fact;
            }
            factx = powmod(factx, p-2);
            facty = powmod(facty, p-2);
            fact = (fact * factx) % p;
            fact = (fact * facty) % p;
            cout << fact << '\n';
        }
    }
}
