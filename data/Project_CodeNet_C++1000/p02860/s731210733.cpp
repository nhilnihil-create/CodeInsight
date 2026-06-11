#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N;
  string s; cin>>s;
  int count=0;
  if(N%2!=0) cout<<"No"<<endl;
  else{
    for(int i=0;i<N/2;i++){
      if(s.at(i)!=s.at(N/2+i)) count++;
    }
    if(count==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  } 
}