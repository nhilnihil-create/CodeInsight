#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int,int>>> a;

bool search(int bits){
  for(int i=0; i<n; ++i){
    if(!(bits&(1<<i))) continue;
    for(auto& j:a[i]){
      int x=j.first,y=j.second;
      if((bits>>x)&1^y) return false;
    }
  }
  return true;
}

int main(void){
  cin>>n;
  a.resize(n);
  for(int i=0; i<n; ++i){
    int b; cin>>b;
    a[i].resize(b);
    for(auto& j:a[i]){ cin>>j.first>>j.second; --j.first;}
  }
  int res=0;
  for(int bits=0; bits<(1<<n); ++bits){
    if(search(bits)){
      int i=bits,cnt=0;
      while(i) ++cnt,i&=i-1;
      res=max(res,cnt);
    }
  }
  cout<<res;
  return 0;
}