#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main() {
	int n,m;
  	cin>>n>>m;
  
  string ans;
  if(n==1)ans="0";
  else if(n==2)ans="10";
  else ans="100";
  
  int count1=true;
  string count2="000";

  rep(i,m){
  	int a;char b;cin>>a>>b;a--;
    if(n>=2&&a==0&&b=='0'){
    	count1 = false;break;
    }
    
    else if(count2[a]=='0'){
    	ans[a]=b;
      	count2[a]='1';
    }
    else if(ans[a]!=b){
    	count1=false;
      	break;
    }
  }
    
    if(count1)cout<<ans<<endl;
    else cout<<-1<<endl;
      
  

}