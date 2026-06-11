#include <iostream>
#include <stdio.h>
#include <string.h>
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
    if(a >= b)return gcd(a % b, b);
    else return gcd(a, b % a);
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

int co[505][505];
int main(){
    int T, m, n, i, j, k, K;
    scanf("%d", &n);
    k = 1;
    while((1<<k) < n)k++;
    DBG(k)
    rep(i, 0, n){
        rep(j, i+1, n){
            rep(l, 0, k)if((i >> l & 1) != (j >> l & 1)){
                printf("%d ", l+1);
                break;
            }
        }
        puts("");
    }
}
