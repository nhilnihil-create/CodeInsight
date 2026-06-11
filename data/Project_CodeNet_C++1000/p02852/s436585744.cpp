#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  string s;cin>>s;
  int64_t a=N;
  vector<int>ans;bool x=true;ans.push_back(N);
  while(0<a){
  int b=-1;
    for(int i=1;(i<=M &&0<=a-i);i++)
    if(s.at(a-i)=='0')b=a-i;
    if(b!=-1){ans.push_back(b);a=b;}else{x=false;break;}
  
  }int n=ans.size();
 if(x){ for(int i=n-1;2<=i;i--)
    cout<<ans.at(i-1)-ans.at(i)<<" ";
  cout<<ans.at(0)-ans.at(1)<<endl;
      }else
   cout<<-1<<endl;
    
  return 0;
}