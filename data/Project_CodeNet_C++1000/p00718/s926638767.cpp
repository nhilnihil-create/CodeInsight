#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define RFOR(i,m,n) for(int i=m;i>=n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265


int f(string s){
  int ans =0;
  rrep(i,s.size()-1){
    if(s[i]=='i'){
      if(i-1<0||!('2'<=s[i-1]&&s[i-1]<='9'))
        ans+=1;
      else
        ans+=1*(s[i-1]-'0');
    }
    if(s[i]=='x'){
      if(i-1<0||!('2'<=s[i-1]&&s[i-1]<='9'))
        ans+=10;
      else
        ans+=10*(s[i-1]-'0');
    }
     if(s[i]=='c'){
      if(i-1<0||!('2'<=s[i-1]&&s[i-1]<='9'))
        ans+=100;
      else
        ans+=100*(s[i-1]-'0');
     }
     if(s[i]=='m'){
      if(i-1<0||!('2'<=s[i-1]&&s[i-1]<='9'))
        ans+=1000;
      else
        ans+=1000*(s[i-1]-'0');
     }
    }

  return ans;
}

string g(int n){
  string s;
  if(n>=1000){
    if(n/1000!=1)
    s+=n/1000 + '0';
    s+='m';
    n%=1000;
  }
 if(n>=100){
   if(n/100!=1)
    s+=n/100 + '0';
    s+='c';
    n%=100;
  }

 if(n>=10){
   if(n/10!=1)
    s+=n/10 + '0';
    s+='x';
    n%=10;
  }

 if(n>=1){
   if(n!=1)
    s+=n + '0';
    s+='i';
  }
  return s;
}


int main(){
  int n;
  cin>>n;
  rep(i,n){
    string s,t;
    cin>>s>>t;
    int a = f(s);
    int b = f(t);
    
    cout<<g(a+b)<<endl;
  }

  return 0;
}
