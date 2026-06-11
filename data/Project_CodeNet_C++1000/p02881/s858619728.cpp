#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

bool IsPrime(ll num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main(){
    ll n;   cin >> n;

    ll ans(1000000000000);

    if(IsPrime(n))
        cout << n-1 << endl;
    else{
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                ans = min(ans,i+n/i-2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}