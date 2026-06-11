#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,j;
  cin >> n;
  vector<char> c(10);
  vector<string> s(n);
  for(i=0;i<n;i++){
    for(j=0;j<10;j++){
      cin >> c.at(j);
    }
    sort(c.begin(),c.end());
    for(j=0;j<10;j++){
      s.at(i) += c.at(j);
    }
  }
  sort(s.begin(),s.end());
  ll x=1,a=0;
  /*cout << s.at(0) << " " << x << endl;*/
  for(i=1;i<n;i++){
    if(s.at(i)!=s.at(i-1)){
      a += x*(x-1)/2;
      x=1;
    }else{
      x++;
    }
    /*cout << s.at(i) << " " << x << endl;*/
  }
  a += x*(x-1)/2;
  
  cout << a << endl;
}