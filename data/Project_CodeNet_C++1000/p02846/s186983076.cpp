#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

ll T1, T2, A1, A2, B1, B2, ans=0, tmp=0;

signed main(){
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    if(A1*T1+A2*T2==B1*T1+B2*T2) {
        cout << "infinity" << endl;
        return 0;
    }
    if(A1>B1&&A2*T2+A1*T1>B2*T2+B1*T1||A1<B1&&A2*T2+A1*T1<B2*T2+B1*T1) {
        cout << 0 << endl;
        return 0;
    }
    ans = abs((A1-B1)*T1)/abs((A1-B1)*T1+(A2-B2)*T2);
    ans = 2*ans+1;
    //cout << ans << endl;
    if(abs((A1-B1)*T1)%abs((A1-B1)*T1+(A2-B2)*T2)==0) {
        ans--;
    }
    cout << ans << endl;
    return 0;
}