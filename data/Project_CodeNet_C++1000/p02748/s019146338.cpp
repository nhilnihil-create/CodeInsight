#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    vi a(A), b(B);
    int mina = 999999, minb = 999999;
    rep(i, A){
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    rep(i, B){
        cin >> b[i];
        minb = min(minb, b[i]);
    }

    int ans = mina + minb;
    
    //値引き
    int x, y, c;
    while(M-- > 0){
        cin >> x >> y >> c;
        ans = min(ans, a[x-1]+b[y-1]-c);
    }

    cout << ans << endl;
    return 0;
}