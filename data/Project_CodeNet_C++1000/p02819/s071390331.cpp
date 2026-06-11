/*
     “You just can’t beat the person who won’t give up.”
                                                            */
#include <bits/stdc++.h>
#define ll long long
#define oo 0x3f3f3f3f3f3f3f3fLL
#define lp(i,n) for(int i = 0;i < int(n);i++)
#define sz(s) (int)(s.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
const int maxn=2e5+5;
const  double EPS = 1e-9;
const int mod = 1e9+7;

inline void File()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
vector<int> is_prime(maxn, 1);
void sieve (){
  is_prime[0] = is_prime[1] = 0;
for (int i = 2; i * i <= maxn; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= maxn; j += i)
            is_prime[j] = 0;
    }
}
}
int main()
{
    ios_base::sync_with_stdio(0);
    File();
    sieve();
    int n;
    cin >> n;
    for(int i = n ; i<= maxn ;i++)
        if(is_prime[i])
         return cout<<i,0;
}
