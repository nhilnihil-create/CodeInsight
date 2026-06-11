#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n; cin >>n;
  vector<long long>a(n);
  for(long long i=0;i<n;i++)cin>>a[i];
  map<long long,long long>mp;
  for(long long i=0;i<n;i++){
    if(mp.count(a[i]))mp.at(a[i])++;
    else mp[a[i]]=1;
  }
  long long kotae=0;
  long long sum=0;
  auto begin=mp.begin(),end=mp.end();
  for(auto iter=begin;iter!=end;iter++){
    long long kazu=iter->second;
    sum+=kazu*(kazu-1)/2;
  }
  for(long long i=0;i<n;i++){
    kotae=sum;
    long long kazu=mp[a[i]];
    kotae-=kazu*(kazu-1)/2;
    kazu--;
    kotae+=kazu*(kazu-1)/2;
    cout<<kotae<<endl;
  }
  return 0;
}
