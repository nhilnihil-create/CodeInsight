#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <iomanip>
#include <stack>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define pi acos(-1)
#define mod 998244353//1000000007
#define inf 1000000007
#define ll long long
#define ull unsigned long long
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
#define N 200005
template <class U,class T> void Max(U &x, T y){if(x<y)x=y;}
template <class U,class T> void Min(U &x, T y){if(x>y)x=y;}
//template <class T> void add(int &a,T b){a=(a+b)%mod;}
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}

int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=1LL*ans*a%mod;
        a=1LL*a*a%mod;b>>=1;
    }
    return ans;
}
int pow(int a, int b, int c){
    int ans = 1;
    while(b){
        if(b&1)ans = 1LL * ans * a % c;
        a = 1LL * a * a % c;
        b >>= 1;
    }
    return ans;
}

int a[N], b[N];
int main(){
    int T, m, i, j, k, n, K;
    scanf("%d", &n);
    set<pii>s;
    rep(i, 0, n)scanf("%d", &a[i]);
    rep(i, 0, n){
        scanf("%d", &b[i]);
    }
    rep(i, 0, n){
        if(b[i] < a[i]){
            puts("-1");
            return 0;
        }
        else if(b[i] > a[i]){
            s.insert({b[i], i});
        }
    }
    ll ans = 0;
    while(!s.empty()){
        auto it = s.end();it--;
        i = it->y;
        s.erase(it);
        j = (i-1+n) % n;
        k = (i+1) % n;
        int dv = b[j] + b[k];
        int v = b[i] - a[i];
        if(a[i] >= dv){
            if(v % dv){
                puts("-1");return 0;
            }
            ans += v / dv;
            b[i] = a[i];
            continue;
        }
        else{
            K = b[i] / dv;
            if(K == 0)K = 1;
            ans += K;
            b[i] -= K * dv;
        }
        if(b[i] < a[i]){
            puts("-1");
            return 0;
        }
        else if(b[i] > a[i])s.insert({b[i], i});
    }
    printf("%lld\n", ans);
}
