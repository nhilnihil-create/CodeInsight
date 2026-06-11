#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=0;
  int N=s.size();
  int i=0;int a=2;
  while(i<N-1){
  if(a==2){ans++; a=1;i++;}
    else{
    if(s.at(i)==s.at(i-1)){ans++; a=2; i+=2;}
      else{ans++; i++;}
    }
  }if(i==N-1 &&(a==2 || s.at(N-1)!=s.at(N-2)))ans++;
  cout<<ans<<endl;
  return 0;
}
