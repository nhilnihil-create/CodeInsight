#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;

int main(){
    int x,a;
    cin>>x>>a;
    int ans = x<a ? 0 : 10;
    cout<<ans<<endl;
}