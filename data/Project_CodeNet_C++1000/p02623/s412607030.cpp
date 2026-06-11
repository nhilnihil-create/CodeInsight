#include <iostream>
#include <algorithm>
#include <vector>
  

using namespace std;
int main() {
  long long int a,b,c,tmp,ans=0,zero=0;
  cin >> a >> b >> c;
  vector <long long int> d(a+1);
  vector <long long int> e(b+1);
  d.at(0)=0,e.at(0)=0;
  for(int i = 1;i<a+1;i++){
    cin >> tmp;
    if((d.at(i-1)+tmp)<=c)d.at(i)=d.at(i-1)+tmp;
    else d.at(i) = c+1;
  }
  for(int i = 1;i<b+1;i++){
    cin >> tmp;
    if((e.at(i-1)+tmp)<=c)e.at(i)=e.at(i-1)+tmp;
    else e[i] = c+1;
  }
  if(d.at(1)>c&&e.at(1)>c)cout << 0;
  else if((d.at(a)+e.at(b))<=c) cout <<  a+b;
  else {
    for(int i = 0;i<a+1;i++){
    long long int sum = 0;
    tmp = d.at(i);
    if(tmp>c) break;
    for(int j=max(zero,ans-i);j<b+1;j++){
    if((tmp+e.at(j))<=c){
      sum = i+j;
     
    }
     else break;
    }
    ans = max(ans,sum);
    }
  cout << ans;
  }
}