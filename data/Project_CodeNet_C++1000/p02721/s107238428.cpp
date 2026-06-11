#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int main(){
  int n,k,c; cin >>n >>k >>c;
  string s; cin >>s;
  int cnt=0;
  vector<int> ans;
  rep(i,n){
    if(s[i]=='x') continue;
    cnt++;
    ans.push_back(i);
    if(cnt>k) return 0;
    i+=c;
  }
  int m=ans.size(),lim=n;
  while(m){
    m--;
    int r=ans[m];
    repa(i,r+1,lim){
      if(s[i]=='o') r=i;
    }
    if(r!=ans[m]) ans[m]=-1;
    lim=r-c;
  }
  for(int x:ans){
    if(x>=0) print(x+1);
  }
}
