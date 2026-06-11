#include <bits/stdc++.h>
using namespace std;

vector<int> zalg(string s){
  int n=s.size();
  vector<int> a(n,0);
  a[0]=n;
  int i=1,j=0;
  while(i<n){
    while(i+j<n && s[i+j]==s[j]) ++j;
    a[i]=j;
    if(j==0){
      ++i;
      continue;
    }
    int k=1;
    while(i+k<n && a[k]<j-k){
      a[i+k]=a[k];
      ++k;
    }
    i += k;
    j -= k;
  }

  return a;
}

int b(string s){
  int n=s.size();
  vector<int> a=zalg(s);
  int res=0;
  for(int i=1;i<s.size();++i){
    res=max(res,min(a[i],i));
  }
  return res;
}


int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int ans=0;
  for(int i=0;i<n;++i){
    string t;
    for(int j=i;j<n;++j) t.push_back(s[j]);
    ans=max(ans,b(t));
  }
  cout<<ans<<endl;
}