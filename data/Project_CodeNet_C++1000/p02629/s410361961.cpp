#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
using namespace std;
typedef long long ll;


int main(){
  
  unsigned long long n,tmp;
  cin >> n;
  int i=1;

  while(n>tmp){
    tmp+=pow(26,i);
    i++;
  }
  i--;
  
  //cout << i << endl;
  vector <char> rev(i);
  rep(j,i){
    char c;
    if(n%26!=0){
  	 c='a'+n%26-1;
      n/=26;
    }else{
     c='a'+25;
      n=n/26-1;
    }
    rev.at(j)=c;

   
  }
  

 reverse(rev.begin(),rev.end());
  
    rep(j,i)
      cout << rev.at(j);
  
  cout << endl;
      

  
}

