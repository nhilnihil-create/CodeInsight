#include <bits/stdc++.h>
using namespace std;
int main() {
 string s,ans;
 int K;
 cin>>K;
 cin>>s;
 
 if(s.size()>K){
  for(int i=0;i<K;i++){
    ans+=s[i];
  }
    ans+="...";
    cout<<ans<<endl;
}
 else if(s.size()<=K){
   ans=s;
   cout<<ans<<endl;
 }
 return 0;
}
