#include <iostream>
#include <cstdio>
using namespace std;
long long int A,B;
long int C,D;
long int eu(long int x,long int y){
    while(1){
        if(x<y) swap(x,y);
        if(!y) break;
        x %= y;
    }
    return x;
}
int main(){
    cin >> A >> B >> C >> D;
    int count = 0;
    long int bc,bd,bcd,ac,ad,acd;
    bc = B / C;
    bd = B / D;
    long  int cd=(C*D)/eu(C,D);
    bcd = B / cd;
    B = B - bc -bd + bcd;
    long long int A1=A-1;
    ac = A1 / C;
    ad = A1 / D;
    acd=A1/cd;
    A = A1 - ac -ad + acd;
    long  int C = B -A;

    printf("%ld\n",C);
}