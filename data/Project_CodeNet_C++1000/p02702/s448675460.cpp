#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

int power(int a, int m, int p){
    int ans = 1;
    while(m>0){
        if(m&1){
            ans *= a % p;
        }
        a *= a % p;
        m>>=1;
    }
    return ans;
}

int main(void){
    // abc164
    string s;
    cin >> s;

    int n = s.length();
    int a[n];
    int mp[2019] = {0};
    mp[0] = 1; //a0 = 0だから
    ll sub = 0;
    int tenfactor = 1;
    REP(i,n){
        sub += (s[n-i-1] - '0') * tenfactor % 2019;
        tenfactor = tenfactor * 10 % 2019;
        a[i] = sub % 2019;
        sub %= 2019;
        mp[a[i]]++;
    }

    ll ans = 0;
    REP(i,2019) ans += mp[i] * (mp[i]-1) / 2;
    cout << ans << endl;
    
    return 0;
}