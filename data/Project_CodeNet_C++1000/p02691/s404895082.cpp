#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n; cin>>n;
  vector<int> a(n);
  for(int i=0; i<n; ++i) cin>>a[i];
  unordered_map<int,int> mp3,mp4;
  long long res=0;
  for(int i=0; i<n; ++i){
    res+=mp3[i+a[i]];
    res+=mp4[i-a[i]];
    mp3[i-a[i]]++;
    mp4[i+a[i]]++;
  }
  cout<<res;
  return 0;
}
  