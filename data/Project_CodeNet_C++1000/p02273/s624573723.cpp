#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

struct Zahyou{double x; double y;};

Zahyou Wa(Zahyou a,Zahyou b){
    Zahyou c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Zahyou Sa(Zahyou a,Zahyou b){
    Zahyou c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

Zahyou Triple(Zahyou a,Zahyou b){
    Zahyou c;
    c.x = (b.x - a.x)/3;
    c.y = (b.y - a.y)/3;
    return c;
}

Zahyou Top(Zahyou a,Zahyou b){
    Zahyou k,c;
    k = Sa(b,a);
    c.x = k.x *cos(M_PI/3) - k.y *sin(M_PI/3);
    c.y = k.x *sin(M_PI/3) + k.y *cos(M_PI/3);
    return Wa(a,c);
}

void disp(Zahyou a){
    printf("%.8f %.8f\n",a.x,a.y);
}

void Koch(int n,Zahyou l,Zahyou r){
    if (n == 0 ) {
        return;
    }
    Zahyou mid1,mid2,top;
    mid1 = Wa(l,Triple(l,r));
    mid2 = Wa(mid1,Triple(l,r));
    top = Top(mid1,mid2);
    
    if(n == 1){
        disp(mid1);
        disp(top);
        disp(mid2);
        disp(r);
    }
    
    Koch(n-1,l,mid1);
    Koch(n-1,mid1,top);
    Koch(n-1,top,mid2);
    Koch(n-1,mid2,r);
}


int main(){
    int n;
    cin >> n;
    Zahyou A,B;
    A.x = 0; A.y = 0;
    B.x = 100; B.y = 0;
    disp(A);
    Koch(n,A,B);
    if (n==0) {
        disp(B);
    }
    return 0;
}