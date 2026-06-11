#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(long long i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define For(i, s, e) for(int i = s;i <= e;i++)
#define Sort(v, n) sort(v, v+n);
#define VSort(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
#define cY cout<<"Yes";
#define cN cout<<"No";
#define cA(a) cout<<a;
const ll MOD = 1000000007;



int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) {
        cin >> a[i];
    }
    int num = 0;
    rep(i,n) {
        num ^= a[i];
    }
    if(num)cN
    else cY
}
