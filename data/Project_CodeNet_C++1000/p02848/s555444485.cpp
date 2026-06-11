#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
using ll = long long;
int main(){
  int a;
  cin >> a;
  string s;
  cin >> s ;
  rep(i,s.length()){
    if(s[i]+a>=91){
      s[i] = s[i]+a-26;
    }else{
      s[i]+=a;
    }
}
cout << s <<  endl;
  return 0;
}