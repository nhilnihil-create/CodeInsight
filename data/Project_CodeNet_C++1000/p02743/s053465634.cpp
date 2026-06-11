#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ld A,B,C;
    cin>>A>>B>>C;
    ll D=A;
    ll E=B;
    ll F=C;
    ld G=2.0*sqrt(A);
  	ld H=sqrt(B);
    if(ld(D+E+G*H)<ld(F)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
