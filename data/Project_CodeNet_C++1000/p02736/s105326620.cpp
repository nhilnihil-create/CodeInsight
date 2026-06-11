#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  string s;
  cin>>s;

  vector<int> as;
  for(char c:s) as.emplace_back(c-'1');

  auto comb=[&](int n,int k){return (n|k)==n;};

  {
    int parity=0;
    for(int i=0;i<n;i++)
      parity+=comb(n-1,i)*(as[i]==1);
    parity%=2;
    if(parity) drop(1);
  }

  if(count(as.begin(),as.end(),1)) drop(0);

  {
    int parity=0;
    for(int i=0;i<n;i++)
      parity+=comb(n-1,i)*(as[i]==2);
    parity%=2;
    drop(parity*2);
  }
  return 0;
}
