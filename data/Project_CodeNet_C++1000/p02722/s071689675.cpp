
// Problem : F - Division or Subtraction
// Contest : AtCoder - AtCoder Beginner Contest 161
// URL : https://atcoder.jp/contests/abc161/tasks/abc161_f
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n;

bool check(int n, int k){
    while(n%k == 0) n /= k;
    return n%k == 1;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n;
    if(n == 2) return cout<<1, 0;
    int ans = 0;
    n--;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            if(i==1 || i==n/i) ans++;
            else ans += 2;
        }
    }
    n++;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            if(i==1 || i==n/i){
                if(check(n,n/i)) ans++;
            } else {
                if(check(n,i)) ans++;
                if(check(n,n/i)) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
