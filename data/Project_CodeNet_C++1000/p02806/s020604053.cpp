#include <bits/stdc++.h>
using namespace std;

int main() {
int n;
cin>>n;
int len[n];
map<string,int> m;
string temp;
int l;
for(int i=0;i<n;i++){
    cin>>temp;
    cin>>l;
    m.insert({temp,i});
    len[i]=l;
}
string s;
cin>>s;
auto it= m.find(s);
int ind= it->second;
int ans=0;
for(int i=ind+1;i<n;i++){
    ans+= len[i];
}
cout<<ans;
  return 0;
}