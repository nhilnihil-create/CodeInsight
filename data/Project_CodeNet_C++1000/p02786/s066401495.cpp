#include <bits/stdc++.h>
using namespace std;
int main(){
    long long h, msb=39; cin >> h;
    bitset<40> b(h);
    while(!b.test(msb)) msb--;
    cout << setprecision(15) << pow(2,msb+1)-1 << endl;
    return 0;
}