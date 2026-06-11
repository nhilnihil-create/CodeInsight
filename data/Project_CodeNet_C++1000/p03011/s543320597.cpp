#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
    int p,q,r;cin>>p>>q>>r;
    cout<<min({p+q,q+r,r+p})<<endl;
}