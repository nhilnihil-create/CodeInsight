#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define mp make_pair
ll mod = 10e9+7;
ll mod2 = 998244353;

int main(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    rep(i,0,k){
        vector<int> base(n,0);
        rep(j,0,n){
            base[max(j-a[j],0)]++;
            if (j+a[j]+1<n){
                base[j+a[j]+1]--;
            }
        }
        vector<int> b(n,0);
        b[0] = base[0];
        rep(i,1,n){
            b[i]=b[i-1]+base[i];
        }
        if (a==b) break;
        a = b;
    }
    rep(i,0,n){
        cout<<a[i]<<endl;
    }
}