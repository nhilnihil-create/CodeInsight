#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define x first
#define y second
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = b-1; i >= a; i--)
#define DBG(x) cerr << (#x) << "=" << x << "\n";
#define ll long long
#define inf 1000000007
#define mod 1000000007
#define N 100005

template<typename U, typename V> void Min(U &a, const V & b){if(a > b)a = b;}
template<typename U, typename V> void Max(U &a, const V & b){if(a < b)a = b;}
template<typename U, typename V> void add(U &a, const V & b){a = (a + b) % mod;} 
template<typename U> U gcd(U a, U b){
	if(a == 0)return b;
    if(b == 0)return a;
	if(a >= b)return gcd(a-b, b);
	else return gcd(a, b - a);
} 
int pow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

char s[N << 1];
int main(){
    int T, m, n, i, j, k, K;
    scanf("%d%s", &n, s);
    if(s[0] == 'W'){
        puts("0");return 0;
    }
    int x = 1, l = 1, r = 0, ans = 1;
    rep(i, 1, n *2){
        if(s[i] == s[i-1])x ^= 1;
        if(x == 1)l++;
        else r++;
        if(x == 0){
            if(l < r){
                puts("0");
                return 0;
            }
            ans = 1LL * ans * (l - r + 1) % mod;
        }
    }
    if(l != r){
        puts("0");
        return 0;
    }
    rep(i, 1, n+1)ans = 1LL * ans * i % mod;
    printf("%d\n", ans);
}
