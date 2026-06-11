#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const int INF=1e9;

int main(){
  int n;
  cin>>n;
  vector<P> st(n);

  rep(i,n){
    int x,l;
    cin>>x>>l;
    st[i].second=x-l;
    st[i].first=x+l; //sortのため．
  }
  sort(st.begin(),st.end());

  int t_min=-INF;
  int Nrobot=0;

  rep(i,n){
    if(st[i].second>=t_min){//追加
      t_min=max(t_min, st[i].first);
      Nrobot++;
      //cout<<st[i].second<<" "<<st[i].first;
    }

  }
  cout<<Nrobot<<endl;
}
