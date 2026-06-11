#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,a=0;cin>>N;
  vector<string>s(N);
  vector<int>t(N);
  for(int i=0;i<N;i++)cin>>s.at(i)>>t.at(i);
  string X;cin>>X;
  int i=0;while(s.at(i)!=X)i++;
  for(i++;i<N;i++)a+=t.at(i);
  cout<<a<<endl;
}