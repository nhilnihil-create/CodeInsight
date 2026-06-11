#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
int main(){
  string s,t;
  cin>>s>>t;
  ll count=0;
  rep(i,s.size()){
    if(s[i]!=t[i]) count++;
  }
  cout<<count;
return 0;
}