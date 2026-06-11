#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W, M;
  cin>>H>>W>>M;
  map<int, int> tate, yoko;
  vector<int> tatearr, yokoarr;
  int h, w;
  map<pair<int, int>, int> amap;
  for(int i=0;i<M;++i) {
    cin>>h>>w;
    h--;
    w--;
    if(tate[h]==0) tatearr.push_back(h);
    if(yoko[w]==0) yokoarr.push_back(w);
    amap[mp(h, w)]++;
    tate[h]++;
    yoko[w]++;
  }
  int maxh=0, maxw=0;
  for(int i=0;i<tatearr.size();++i) {
    maxh = max(maxh, tate[tatearr[i]]);
  }
  for(int i=0;i<yokoarr.size();++i) {
    maxw = max(maxw, yoko[yokoarr[i]]);
  }
  vector<int> harr, warr;
  for(int i=0;i<tatearr.size();++i) {
    if(tate[tatearr[i]]==maxh) harr.push_back(tatearr[i]);
  }
  for(int i=0;i<yokoarr.size();++i) {
    if(yoko[yokoarr[i]]==maxw) warr.push_back(yokoarr[i]);
  }
  int ans = maxh+maxw;
  bool ari = true;
  for(int i=0;i<harr.size();++i) {
    for(int j=0;j<warr.size();++j) {
      if(amap[mp(harr[i], warr[j])]==0) {
        ari = false;
        break;
      }
    }
    if(!ari) break;
  }
  if(ari) ans--;
  cout<<ans<<endl;
}

