#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  reverse(s.begin(),s.end());
  map<int64_t,int64_t>tmp;
  int64_t size=s.size();
  vector<int64_t>t(size);
  vector<int64_t>amari(size+100,0);
  amari.at(1)=10;
  for(int64_t i=2;i<=size+99;i++){
    amari.at(i)=amari.at(i-1)*10%2019;
  }
  t.at(0)=(int64_t)s.at(0)-'0';
  tmp[0]=1;
  tmp[t.at(0)]=1;
  for(int64_t i=1;i<size;i++){
    t.at(i)=(t.at(i-1)+amari.at(i)*((int64_t)s.at(i)-'0')%2019)%2019;
    if(tmp.count(t.at(i)))tmp.at(t.at(i))++;
    else tmp[t.at(i)]=1;         
  }
  int64_t ans=0;
  for(auto tmpi:tmp){
    ans+=(tmpi.second*(tmpi.second-1))/2;
  }
  cout <<ans<<endl;
}