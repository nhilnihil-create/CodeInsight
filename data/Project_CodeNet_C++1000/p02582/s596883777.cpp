#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int count = 0, ans = 0;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == 'S'){
      ans = max(count, ans);
      count = 0;
   } else {
      count++;
   }
}
 ans = max(count, ans);
cout<<ans<<endl;
return 0;
}