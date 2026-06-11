#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};
int main()
{
  int n,k;
  cin>>n>>k;
  long long lsum=0;
  int left=k-1;
  int right=n-k+1;
  for(int i=0;i<k;i++)lsum+=i;
  long long rsum=0;
  for(int i=n;i>(n-k);i--)rsum+=i;
  mint ans=0;
  ans+=(rsum-lsum+1);
  for(int i=k+1;i<=n+1;i++)
  {
    left++;
    lsum+=left;
    right--;
    rsum+=right;
    ans+=(rsum-lsum+1);
  }
  cout<<ans.x<<endl;
  return 0;
}