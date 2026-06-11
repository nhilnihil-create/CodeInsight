#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <bitset>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll ans=0;
    for(int i=n-1;i>n/2;i--) ans+=A[i];
    for(int i=n-2;i>=n/2;i--) ans+=A[i];
    if(n%2==0) ans+=A[n/2];
    cout << ans << endl;
}