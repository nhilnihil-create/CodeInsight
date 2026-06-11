#include<iostream>
#include<vector>
using namespace std;
typedef long long li;
#define yn(i) print((i)?"Yes":"No")
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }


int main() {
  int n; li k; cin >>n >>k;
  vector<int> a(n); for(auto& x:a){ cin >>x; x--; }
  vector<int> seen(n);
  seen[0]=1;
  int tmp=a[0],cnt=1;
  while(seen[tmp]==0){
    cnt++;
    seen[tmp]=1;
    tmp=a[tmp];
  }
  int tail=0,tmp2=0;
  while(tmp2!=tmp){
    tail++;
    tmp2=a[tmp2];
  }
  
  if(k<=cnt){
    int ans=0;
    rep(i,k){
      ans=a[ans];
    }
    print(ans+1);
    return 0;
  }
  
  int T=cnt-tail;
  li q=(k-tail)/T,r=(k-tail)%T;
  k=min(k,(li)tail);
  int ans=0;
  rep(i,tail+r){
    ans=a[ans];
  }
  print(ans+1);
}
