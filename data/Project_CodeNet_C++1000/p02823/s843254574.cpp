#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){

    ull N, A, B;
    cin >> N >> A >> B;

    ll min_value = min(A-1, N-B);
    ll dif = B - A;
    ll ans = 0;

    if (dif%2 == 0){
        ans = dif/2;
    }
    else{
        ans = min_value + 1 + (B-A-1)/2;
    }

    cout << ans << endl;
    return 0;    
}