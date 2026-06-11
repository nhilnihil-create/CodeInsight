#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    ll n, k; cin >> n >> k;
    vector<int> ans;
    while(n){
        ans.emplace_back(n % k);
        n /= k;
    }
    reverse(All(ans));
    cout << ans.size() << endl;
    system("pause");
}

//https://www.geisya.or.jp/~mwm48961/kou3/base2.htm
//https://math.nakaken88.com/textbook/basic-base-conversion-of-integers/
