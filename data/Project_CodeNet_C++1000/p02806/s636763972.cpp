#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1001001001;
const ll mod = 1000000007;
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
bool isp(ll n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}

int main() {
    ll N;
    cin >> N;
    vector<string> kyoku(N);
    vector<ll> time(N);
    bool ok = false;
    string target;
    rep(i,N){
        cin >> kyoku[i] >> time[i];
    }
    ll ans = 0;
    cin >> target;
    rep(i,N){
        if(ok)ans += time[i];
        if(kyoku[i] == target)ok = true;
    }
    cout << ans << endl;
}