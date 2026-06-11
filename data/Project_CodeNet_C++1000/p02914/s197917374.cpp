
#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
typedef unsigned long long int  ull;
const int MOD = 1000000007;
 
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;



ull check_bit(ull N,int POS){return (N & (1ULL<<POS));}

vector<ull>v;
ull gaussian_elimination()
{
    int n=v.size();
    int ind=0;  // Array index
    for(int bit=log2(v[0]);bit>=0;bit--)
    {
        int x=ind;
        while(x<n&&check_bit(v[x],bit)==0)
          x++;
        if(x==n)
          continue; // skip if there is no number below ind where current bit is 1
        swap(v[ind],v[x]);
        for(int j=0;j<n;j++)
        {
            if(j!=ind&&check_bit(v[j],bit))
                v[j]^=v[ind];
        }
        ind++;
    }
    ull ans=v[0];
    for(int i=1;i<n;i++)
      ans=max(ans,ans^v[i]);
    return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin >> n;
  ull all = 0;
  ll mbit = 0;
  rep(i,n){
      ull tmp; cin >> tmp;
      v.push_back(tmp);
      all = all^tmp;
  }
  rep(i,n){
      v[i] = v[i] & (~all);
  }
  sort(v.rbegin(), v.rend());
  cout  << 2 * gaussian_elimination() + all << endl;
}