#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll T1, T2, A1, A2, B1, B2; 
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    ll P = T1*(A1-B1);
    ll Q = T2*(A2-B2);
    if(P+Q==0){
        cout << "infinity" << endl;
        return 0;
    } else if(P+Q<0){
        swap(A1, B1);
        swap(A2, B2);
    }

    if(A1>B1){
        cout << 0 << endl;
        return 0;
    }

    ll s = -P / (P+Q);
    ll t = -P % (P+Q);
    if(t==0) cout << 2*s  << endl;
    else cout << 2*s + 1 << endl;
}