#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define ll long long
using namespace std;
const int lim = 5e6;
int lp[lim + 10],pr[lim],cnt = 0;
vector <ll> V;
unordered_map <ll,int> mp;
ll n;
void sieve(){
    for (int i = 2; i <= lim; i++){
        if (lp[i] == 0) lp[i] = pr[++cnt] = i;
        int j = 1;
        while (j <= cnt && pr[j] <= lp[i] && i * pr[j] <= lim){
            lp[i * pr[j]] = pr[j];
            j++;
        }
    }
}
bool prime(long long x){
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
void add(){
    for (ll i = 2; i <= lim; i++)
        if (lp[i] == i)
            for (ll temp = i; temp <= (ll)1e13; temp *= i)
                V.push_back(temp);
}
int main(){
    /*sieve();
    add();
    sort(V.begin(),V.end());
    cin >> n;
    ll ans = 0 , tmp = 1;
    for (auto x : V)
        if (n % x == 0 && x <= n) n /= x , ans++ , tmp = x;
    if (prime(n) == true && n > tmp) ans++;
    cout << ans;*/
    ll ans = 0;
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0){
            while (n % i == 0){
                n /= i;
                mp[i]++;
            }
            V.push_back(i);
        }
    if (n > 1) V.push_back(n) , mp[n]++;
    for (auto x : V){
        int sum = 1;
        while (mp[x] >= sum) mp[x] -= sum , ans++ , sum++;
    }
    cout << ans;
    return 0;
}