#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    ll ans = 0;
    if ((A - B) % 2 == 0){
        ans = max((A - B) / 2, (B - A) / 2);
    }
    else{
        ans = min(A + (B - A - 1) / 2, (N - B + 1) + (B - A - 1) / 2);
    }
    cout << ans << endl;
}

