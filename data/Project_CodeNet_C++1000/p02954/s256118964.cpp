#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  string s;
  cin >> s;
  int size=s.size();
  vector<int> a(size);
  int rs=0;
  int ls=0;
  int r;
  char p='R';
  for(int i=0;i<size;i++){
    if(p=='R'){
      if(s.at(i)=='R')
      rs++;
      else{
        ls++;
        r=i-1;
        p='L';
      }
    }
    else{
      if(s.at(i)=='L')
      ls++;
      else{
        int sum=rs+ls;
        if(sum%2==0){
          a.at(r)=sum/2;
          a.at(r+1)=sum/2;
        }
        else if(rs%2!=0){
          a.at(r)=sum/2+1;
          a.at(r+1)=sum/2;
        }
        else{
          a.at(r)=sum/2;
          a.at(r+1)=sum/2+1;
        }
        rs=1;
        ls=0;
        p='R';
      }
    }
  }
  int sum=rs+ls;
  if(sum%2==0){
    a.at(r)=sum/2;
    a.at(r+1)=sum/2;
  }
  else if(rs%2!=0){
    a.at(r)=sum/2+1;
    a.at(r+1)=sum/2;
  }
  else{
    a.at(r)=sum/2;
    a.at(r+1)=sum/2+1;
  }
  for(int i=0;i<size;i++){
    cout << a.at(i) << " ";
  }
  cout << endl;
}

