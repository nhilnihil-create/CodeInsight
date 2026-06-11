#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

ll MAX_A = 1e9;
ll n, k, s;

int main()
{
    cin >> n >> k >> s;
    vector<int> ans(n, MAX_A);
    if(s == MAX_A)
    {
        rep(i,n-k) ans[i] = 1;
    }
    else
    {    
        rep(i,k) ans[i] = s;
    }
    rep(i,n) cout << ans[i] << ((i == n - 1)? "\n" : " ");


    return 0;
}