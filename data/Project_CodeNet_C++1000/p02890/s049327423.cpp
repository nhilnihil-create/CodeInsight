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
#include <stack>



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
  vector<int>a(n),b;
  rep(i,n)cin>>a[i];
  map<int,int>ma;
  rep(i,n)ma[a[i]]++;

  for(auto tp:ma)
  {
    b.push_back(tp.second);
  }
  sort(all(b),greater<int>());
  vector<int>res(n+1);
  int s=n;
  int id=1;
  int wei=0;
  rep(i,b.size())
  {
    int nid=s/b[i]+1+wei;
    repi(j,id,nid)
    {
      res[j]=s/(j-wei);
    }
    id=nid;
    s-=b[i];
    wei++;
  }
rep(i,n)  printf("%d\n", res[i+1]);


  return 0;

}
