#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  a--; b--; c--; d--;
  string s;
  cin>>s;
  
  if(c<d){
    for(int i=a+1;i<d-1;i++){
      if(s[i]==s[i+1]&&s[i]=='#'){
        cout<<"No"<<endl;
        return 0;
      }
    }
    cout<<"Yes"<<endl;
    return 0;
  }else{
    for(int i=a+1;i<c-1;i++){
      if(s[i]==s[i+1]&&s[i]=='#'){
        cout<<"No"<<endl;
        return 0;
      }     
    }
    bool ok = true;
    for(int i=b;i<=d;i++){
      if(s[i-1]==s[i]&&s[i]==s[i+1]&&s[i]=='.') ok = false;
    }
    if(ok){
      cout<<"No"<<endl;
      return 0;
    }else{
      cout<<"Yes"<<endl;
      return 0;
    }
  }
}