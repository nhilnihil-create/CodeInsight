#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(void)
{
    ll a,b,c;
    cin >> a >> b >> c;
    if(c-a-b > 0 && (c-a-b)*(c-a-b) - 4* a* b > 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");

    }



}
