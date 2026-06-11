#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<ll>a(n),aa(n);
  rep(i,n)cin>>a[i];
  ll sum,mask;
  sum=0;
  rep(i,n)sum^=a[i];
  mask=(1LL<<61)-1-sum;
  rep(i,n)aa[i]=mask&a[i];
  int id=0;
  for(int i=60;i>-1;i--)
  {
    ll bit=1LL<<i;
    int flag=-1;
    repi(j,id,n)
    {
    //  cout<<aa[j];
      if((bit&aa[j])==bit)
      {
        if(flag==-1)
        {
          if(j!=id)
          {
            swap(aa[id],aa[j]);
          }
          flag=id;
        }
        else
        {
          aa[j]^=aa[flag];
        }
      }
    }
  //  cout<<endl;

    if(flag!=-1)id++;

  }
  ll res=0;
  rep(i,n)
  {
  //  cout<<(bitset<60>)aa[i]<<endl;
    chmax(res,res^aa[i]);
  }
//  cout<<res<<endl;
  cout<<res*2+sum<<endl;
  return 0;

}
