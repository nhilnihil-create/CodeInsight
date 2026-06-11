#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  ll n,k;
  cin>>n>>k;
  vector<ll> p(n),c(n);
  for(auto&& e: p) 
  {
    cin>>e;
    e--;
  }
  for(auto&& e: c) 
  {
    cin>>e;
  }

  ll ans=*max_element(c.begin(), c.end());
  
  //始点を決めたとき，取得できる最大点数を求める．
  for (int start = 0; start < n; ++start)
  {
    //一周するのに何回かかるか調べる
    //一周する間に何点得られるか調べる
    ll cycle_len=0,cycle_cost=0;
    ll i=start;
    do {
      cycle_len++;
      cycle_cost+=c[i];
      i=p[i];
    } while (i!=start);

    /*
    一周して増える場合は何回回って，
    残り何回移動できるか調べる．
    */
    ll point=0;
    ll time=cycle_len;
    if (cycle_cost > 0)
    {
      point+=cycle_cost*(k/cycle_len-1);
      time=cycle_len+k%cycle_len;
    }

    //time回の移動の中で最大何点得られるか決める．
    ll max_point=c[i];
    for (int j = 0; j < time; ++j)
    {
      point+=c[i];
      i=p[i];
      max_point=max(max_point,point);
    }

    ans=max(ans,max_point);
  }
  cout<<ans<<endl;

}