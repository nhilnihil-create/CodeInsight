#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector<int> A(a),B(b);
    
    int mna = mod,mnb = mod;
    for(int i = 0; i < a; i++){
        cin >> A[i];
        mna = min(mna,A[i]);
    }
    for(int i = 0; i < b; i++){
        cin >> B[i];
        mnb = min(mnb,B[i]);
    }
    ll ans = mna+mnb;
    for(int i = 0; i < m; i++){
        int y,x,c;
        cin >> x >> y >> c;
        x--;y--;
        int mon = A[x]+B[y]-c;
        if(ans > mon) ans = mon;
    }
    cout << ans << endl;

    return 0;
}