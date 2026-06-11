#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>> n;
  
  int64_t ans=0;
  for(int a=1; a<=n; a++){
    if(a%10==0) continue;
    string s=to_string(a);
    int head=s[s.size()-1]-48,tail=s[0]-48;
    if (head==tail) ans++;
    
    for(int i=1; head*pow(10,i)+tail<=n; i++){
      if(n/(int)pow(10,i)>head){ ans+=pow(10,i-1); continue;}
      ans+=(n-head*(int)pow(10,i)-tail)/10+1;
    }
  }
  cout<<ans<<endl;
}