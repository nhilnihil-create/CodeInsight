#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  
  int cnt=0;
  int a,b;
  rep(i,10){
    rep(j,10){
      rep(k,10){
        bool flag=false;
        a=n,b=-1;
        for(int l=n-1;l>=0;l--){
          if(s[l]-'0'==i) a=l;
        }
        for(int r=0;r<n;r++){
          if(s[r]-'0'==k) b=r;
        }
        if(a>=0 && b<n && a+1<b){
          for(int m=a+1;m<b;m++){
            if(s[m]-'0'==j) flag=true;
          }
        }
        if(flag) cnt++;
      }
    }
  }
  
  cout<<cnt<<endl;
  
  return 0;
}