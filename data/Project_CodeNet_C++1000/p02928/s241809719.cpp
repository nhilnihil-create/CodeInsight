#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
const int m = 1000000007;
int main() {
    ll n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll inv1=0,inv2=0;
    rep(i, 0, n){
      rep(j, 0, n){
        if(i==j) continue;
        if(a[i]>a[j]){
          if(i<j) inv1++;
          inv2++;
        }
      }
    }
    ll ans=0;
    ans+=(k*inv1)%m;
    ans+=((k*(k-1))/2)%m*inv2;
    ans%=m;
    cout<< ans;
    return 0;
}
