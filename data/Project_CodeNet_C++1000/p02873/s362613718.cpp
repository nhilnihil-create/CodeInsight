#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  vector<int>a(n+1,0);
  for(int i=0;i<n;i++){
    if(s[i]=='<'){
      a[i+1]=a[i]+1;
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]=='>'){
      a[i]=max(a[i],a[i+1]+1);
    }
  }
  long long sum=0;
  for(int i=0;i<n+1;i++){
    //cout<<a[i]<<" ";
    sum+=a[i];
  }
  cout<<sum<<endl;
  return 0;
}