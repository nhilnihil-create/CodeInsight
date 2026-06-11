#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, A, B;
    cin >> N >> A >> B;
    ll ans = 0;
    if(A % 2 == 0 && B % 2 == 0)
    {
        ans = (B - A) / 2;
    }else if(A % 2 != 0 && B % 2 != 0){
        ans = (B - A) / 2;
    }
    else
    {
        ans = min(A - 1, N - B) + 1 + ((B - A - 1) / 2);
    }
    cout << ans << endl;
}