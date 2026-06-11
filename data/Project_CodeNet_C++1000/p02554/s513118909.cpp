#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL MO=1e9+7;

LL qmi(LL a,LL b) {
    LL res=1;
    while(b) {
        if (b&1) {
            res=res*a%MO;
        }
        a=a*a%MO;
        b>>=1;
    }
    return res;
}

int main() {
    LL n;
    cin>>n;

    cout<<((qmi(10,n)-2*qmi(9,n)+qmi(8,n))%MO+MO)%MO<<"\n";

    return 0;
}
