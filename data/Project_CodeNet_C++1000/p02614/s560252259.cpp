#pragma GCC optimize("O2")
#include<iostream>
using namespace std;
#define f(x,y,z) for(short int x=y;x<z;++x)
bool b[6][6], r[6], c[6];
short int h, w, k, rr[6], cc[6], m, sm, hs, ht;
char x;
void hit(short int z) {
    if(z == h+w) {
        sm = hs = 0;
        f(i,0,h) if(r[i]) sm += rr[i];
        f(j,0,w) if(c[j]) sm += cc[j];
        f(i,0,h) if(r[i]) f(j,0,w) if(c[j] && b[i][j]) ++hs;
        sm -= hs;
        if(sm == ht-k) ++m;
    } else if(z >= h) {
        hit(z+1);
        c[z-h] = true;
        hit(z+1);
        c[z-h] = false;
    } else {
        hit(z+1);
        r[z] = true;
        hit(z+1);
        r[z] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> h >> w >> k;
    f(i,0,h) f(j,0,w) {
        cin >> x;
        if(x == '.') b[i][j] = false;
        else {
            b[i][j] = true;
            ++rr[i], ++cc[j], ++ht;
        }
    }
    hit(0);
    cout << m << '\n';
}