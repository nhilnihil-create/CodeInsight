#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;
typedef pair<P, LL> PP;
typedef pair<P, LL> PP;
typedef long long LL;

#define xx first
#define yy second

int main()
{
  //freopen("input", "r", stdin);
  // freopen("output", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  multiset<int> si;
  int fl = 1;
  cin>>n;
  for(int i=0;i<(1<<n);i++){
    int t;cin>>t;
    si.insert(t);
  }
  auto eit = si.end();
  eit--;
  vector<int> vp{*eit};
  si.erase(eit);
  while(vp.size()!=(1<<n)){
    vector<int> tp;
    for(auto i:vp){
      tp.push_back(i);
      auto it = si.lower_bound(i);
      if(it==si.begin()){fl = 0;break;}
      it--;
      tp.push_back(*it);
      si.erase(it);
    }
    vp = move(tp);
    if(fl==0)break;
  }
  if(fl)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
