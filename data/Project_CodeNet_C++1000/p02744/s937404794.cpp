#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100;
const ll MOD = 1000000007;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}

int keta(ll num){
    int digits = 0;
    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}


ll mpow(ll x, ll n){//繰り返し二乗法 計算量O(logN)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans * x % MOD;
        x = x * x % MOD;
        n  = n >> 1;
    }
    return ans;
}

int gcd(int a, int b){
    if(a % b == 0) return b;
    else return (gcd(b, a%b));
}



int main(){
    int N;
    cin >> N;
    queue<string> que;
    que.push("a");
    while(!que.empty()){
        string str = que.front(); que.pop();
        if(str.length() == N) cout << str << endl;
        else{
            char mx = 0;
            rep(i, str.length()){
                if(mx < str[i]) mx = str[i];
            }
            mx++;
            for(char c = 'a'; c <= mx; c++){
                que.push(str + c);
            }
        }
    }
}