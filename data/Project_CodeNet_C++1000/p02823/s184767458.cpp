#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long N, A, B;
    cin >> N >> A >> B;

    long long ans = 0;

    if((A - B) % 2 == 0 ){
        ans = abs(A - B) / 2;
    }else{

        long long tmp1 = abs((2*N - A + 1) - B)/2;
        long long tmp2 = abs(-A + 1 - B)/2;

        ans = min({tmp1, tmp2});
    }

    cout << ans << endl;
    return 0;

}