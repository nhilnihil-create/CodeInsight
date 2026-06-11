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

int main()
{
    ios_base::sync_with_stdio(0);
    File();
    int n;
    cin >> n;
    bool pir = true;
    set<int> primes;
    int all_gcd = 0;
    vector<int>arr(n);
    for(int &it : arr){
        cin >> it;
        all_gcd = __gcd(all_gcd, it);
        for(int i = 2; i * i <= it; i++){
            if(it % i)
                continue;
            if(primes.count(i)){
                pir = false;
                break;
            }
            primes.insert(i);
            while(it % i == 0)
                it /= i;
        }
        if(it > 1){
            if(primes.count(it))
                pir = false;
            primes.insert(it);
        }
    }
    if(all_gcd == 1){
        if(pir)
            puts("pairwise coprime");
        else
            puts("setwise coprime");
    }else{
        puts("not coprime");
    }
}
