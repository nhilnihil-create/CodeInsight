#include"bits/stdc++.h"
using namespace std;
int main() {
  string s;
  cin>>s;
  int tot =0;
 
  int N =s.size();
  vector<int> vec(N);
  for(int i =0;i<N;i++){
    vec[i]=s.at(i)-'0';
    tot+=vec[i];
  }
 
  if(tot%9!=0)
    { cout<<"No"<<endl;}
  else
    {cout<<"Yes"<<endl;}
}  
