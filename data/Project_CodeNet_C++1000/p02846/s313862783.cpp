#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll T[2],A[2],B[2],N,D,ans;

int main(void){
    cin >> T[0] >> T[1] >> A[0] >> A[1] >> B[0] >> B[1];
    if(A[0]<B[0]){
        swap(A[0],B[0]);
        swap(A[1],B[1]);
    }
    D = (B[0]*T[0] +B[1]*T[1])-(A[0]*T[0] +A[1]*T[1]);
    //cout << D << endl;
    if(D==0){cout << "infinity" << endl;return 0;}
    if(D<0){cout << 0 << endl;return 0;}
    if(D>0){
        N = (T[0]*A[0] - T[0]*B[0])/D;
        ans = N*2+1;
        if((T[0]*A[0] - T[0]*B[0])%D==0)ans--;
        cout << ans << endl;
    }
    return 0;
}
