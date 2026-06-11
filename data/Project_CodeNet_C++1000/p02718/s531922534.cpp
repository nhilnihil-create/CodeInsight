#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

bool is_prime(ll n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(void)
{
    int n, m, sum=0;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    int cnt=0;
    rep(i,n){
        if(a[i]*4*m < sum) cnt++;
    }
    if(n-cnt >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}