#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int main() {
    long long S;
    cin >> S;
    int x0=0, y0=0;
    long long x1,x2,y1,y2;
    x1=1000000000;
    x2=1;
    y2=S/x1+1;
    y1=x1*y2-S;
    if (S==1000000000000000000){
    cout << 0 << " " << 0 << " ";
    cout << x1 << " " << 0 << " ";
    cout << 0 << " " << x1 << endl;
    }else{
    cout << x0 << " " << y0 << " ";
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << endl;
    }
}