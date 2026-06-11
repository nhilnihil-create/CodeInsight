#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,a,b,c,d,i;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;
  
  int ra,rb;
  i=a;
  while(i<=n-1&&(s.at(i)=='.'||s.at(i+1)=='.')){
    i++;
  }
  ra=i;
  i=b;
  while(i<=n-1&&(s.at(i)=='.'||s.at(i+1)=='.')){
    i++;
  }
  rb=i;
  
  if(c>ra||d>rb){
    cout << "No" << endl;
    return 0;
  }
  
  if(c<d){
    cout << "Yes" << endl;
    return 0;
  }
  
  int judge=0;
  for(i=b;i<=d;i++){
    if(s.at(i-1)=='.'&&s.at(i)=='.'&&s.at(i+1)=='.'){
      judge=1;
    }
  }
  
  if(judge==1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}