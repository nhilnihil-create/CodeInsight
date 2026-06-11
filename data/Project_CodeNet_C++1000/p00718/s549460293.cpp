#include<bits/stdc++.h>
using namespace std;
#define R(i,n) for(int i=0;i<n;++i)
int n,a,b,y[]={1000,100,10,1};
map<char,int> x;
string s,t="mcxi";
main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  x['m']=1000,x['c']=100,x['x']=10,x['i']=1;
  cin>>n;
  R(i,n){
    a=0;
    R(j,2){
      cin>>s;
      R(k,s.size())
        t.find(s[k])!=string::npos?a+=x[s[k]]:a+=(s[k]-'0')*x[s[++k]];
    }
    R(j,4){
      b=1;
      while(a/y[j])a-=y[j],++b;
      --b>1&&cout<<b<<t[j];
      --b||cout<<t[j];
    }cout<<endl;
  }
}