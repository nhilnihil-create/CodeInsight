#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;
  int i;
  vector<int> a(200010,0);
  map<int,int> mp;
  cin >> s;
  reverse(s.begin(),s.end());
  int tmp=1;
  for(i=0;i<s.size();i++){
    a[i+1]=a[i]+tmp*(s[i]-'0');
    a[i+1]=a[i+1]%2019;
    tmp=tmp*10%2019;
  }
  for(i=0;i<=s.size();i++){
    mp[a[i]]++;
  }
  ll ans=0;
  for(i=0;i<=s.size();i++){
    if(mp[a[i]]>=2){
      ans+=mp[a[i]]*(mp[a[i]]-1)/2;
      mp[a[i]]=0;
    }
  }
  cout << ans << endl;
}