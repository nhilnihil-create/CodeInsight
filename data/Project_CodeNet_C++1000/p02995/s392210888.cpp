#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull gcd(ull a, ull b){
    if(b == 0){ return a;}
    else {
        return gcd(b, a % b);
    }
}

int main(void)
{
    ull A, B, C, D;
    cin >> A >> B >> C >> D;

    ull all = B - A + 1;

    ull divC = B / C - (A-1) / C;
    ull divD = B / D - (A-1) / D;
    ull CD = C*D/gcd(max(C,D) , min(C,D));
    ull divCD = B/CD - (A-1)/CD;

    cout << all - (divC + divD - divCD) << endl;
}
