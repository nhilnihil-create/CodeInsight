#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
  int n;cin >>n;
  vector<int>a(n);
  unordered_set<int>s;
  for (int i = 0; i < n; ++i) {
      cin>>a[i];
      s.insert(a[i]);
  }
  sort(all(a));
  if(s.size()>3){
      puts("No");
      return 0;
  }
  vector<int>num;
  int key=a[0];
  int j=0;
  int now=0;
  for (int i = 0; i < n; ++i) {
      if(a[i]!=key){
          num.push_back(now);
          key=a[i];
          now=1;
      }
      else now++;
    }
  if(now!=0){
      num.push_back(now);
  }
  if(n%3!=0){
      if(s.size()!=1)puts("No");
      else if(a[0]!=0)puts("No");
      else puts("Yes");
  }
  else {
      if(s.size()==1){
          if(a[0]==0)puts("Yes");
          else puts("No");
      }
      else if(s.size()==2){
          if(a[0]==0&&num[0]==n/3){
              puts("Yes");
          }
          else puts("No");
      }
      else {
          vector<int>x;
          for(auto e:s){
              x.push_back(e);
          }
          int key=x[0]^x[1]^x[2];
          if(key==0&&num[0]==n/3&&num[1]==n/3) {
              puts("Yes");
          }
          else puts("No");
      }
  }
}
