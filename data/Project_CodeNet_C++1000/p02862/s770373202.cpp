#include <bits/stdc++.h>
using namespace std;

int p(int x,int y) {
    int yy=y;
    long long X=x,count=1;
    while(yy!=0) {
    if (yy%2==1) {
        count*=X;
        count%=1000000007;
    }
    yy/=2;
    X*=X;
    X%=1000000007;
    }
    return count;
}

int main() {
   int X,Y;
   cin >> X >> Y;
   if ((X+Y)%3!=0) cout << 0 << endl;
   else {
       int Z=(X+Y)/3;
       if (Z>X || Z>Y) cout << 0 << endl;
       else {
           X-=Z,Y-=Z;
           long long count=1,x=1,y=1;
           for (int i=1; i<=Z; i++) {
               count*=i;
               count%=1000000007;
               //cout << i << " " << count << endl;
           }
           //cout << Z << endl;
           //cout << count << endl;
           for (int i=1; i<=X; i++) {
               x*=i;
               x%=1000000007;
           }
           //cout << x << endl;
           for (int i=1; i<=Y; i++) {
               y*=i;
               y%=1000000007;
           }
           //cout << y << endl;
           y=p(y,1000000005);
           x=p(x,1000000005);
           count*=x;
           count%=1000000007;
           count*=y;
           count%=1000000007;
           cout << count << endl;
       }
   }
}