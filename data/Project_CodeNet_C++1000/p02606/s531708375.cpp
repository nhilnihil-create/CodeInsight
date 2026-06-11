#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int L,R,d;
    cin >> L >> R >> d;
    int a = (L-1)/d;
    int b = R/d;
    int ans = b-a;
    cout << ans << endl;
}