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


struct ConvexHull{
  using cd=complex<double> ;
  vector<cd> ps,qs;
  int sz;
  ConvexHull(vector<cd> v){
    ps=v;
    sz=ps.size();
    qs.resize(sz*2);
    sort(ps.begin(),ps.end(),[](cd a,cd b){if(a.real()!=b.real()){return a.real()<b.real();}return a.imag()<b.imag();});
    calc();
  }
  void calc(){
    int k=0;
    for(int i=0;i<sz;i++){
      while(k>1 && ((qs[k-1]-ps[i])/(qs[k-2]-ps[i])).imag()<=0)k--;
      qs[k++]=ps[i];
    }
    int t=k;
    for(int i=sz-2;i>=0;i--){
      while(k>t && ((qs[k-1]-ps[i])/(qs[k-2]-ps[i])).imag()<=0)k--;
      qs[k++]=ps[i];
    }
    qs.resize(k-1);
  }
  /*最遠点　尺取
  double farlen()
  {
    double res=0,tres=0;
    int r=1;
    rep(l,qs.size())
    {
      tres=abs(qs[l]-qs[r-1]);
      while(r<qs.size() && chmax(tres,abs(qs[l]-qs[r])))r++;
      chmax(res,tres);
      if(l==r)r++;
    }
    return res;
  }
  */
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<complex<double>>conv;
  int n;
  cin>>n;
  conv.push_back({0,0});
  rep(i,n)
  {
    double x,y;
    cin>>x>>y;
    complex<double>vec(x,y);
    auto tv=conv;
    for(auto j:tv)conv.push_back(j+vec);
    ConvexHull ch(conv);
    ch.calc();
    conv=ch.qs;
    conv.erase(unique(all(conv)),conv.end());


  //  rep(i,ch.qs.size())conv.push_back(ch.qs[i]);
    //rep(i,conv.size())cout<<conv[i]<<endl;
    //cout<<endl;
  }
  double res=0;
  rep(i,conv.size())
  {
    chmax(res,abs(conv[i]));
  }
  cout<<setprecision(12)<<res<<endl;
  return 0;

}
