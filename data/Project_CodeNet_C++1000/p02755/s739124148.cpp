#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int A,B;
    cin >> A >> B;
    int xa,xb;
    xa = (A*100+8-1) / 8;
    xb = (B*100+10-1) / 10;
    int ans;
    if(int(xa*0.10) == B && int(xb*0.08) == A){
        ans = min(xa,xb);
    }
    else if(int(xa*0.10) == B && int(xb*0.08) != A){
        ans = xa;
    }
    else if(int(xa*0.10) != B && int(xb*0.08) == A){
        ans = xb;
    }
    else{
        ans = -1;
    }
    cout << ans << endl;
}
