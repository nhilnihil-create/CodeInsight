#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;



int main(){
  string a,b;
  cin>>a>>b;
  
  int cnt=0;
  rep(i,3){
    if(a[i]==b[i]) cnt++;
  }
  cout<<cnt<<endl;

}
