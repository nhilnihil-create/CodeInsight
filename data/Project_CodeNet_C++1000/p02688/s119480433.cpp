#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,k,d,a;
  cin>>n>>k;
  int ans=0,maxi=0;
  set<int> myset;
  while(k--) {
    cin>>d;
    while(d--) {
      cin>>a;
      myset.insert(a);
    }
  }
  int m=myset.size();
  cout<<n-m<<endl;
  return 0;
}