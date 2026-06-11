#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  long long n,a,b,c,d;
  cin >>n>>a>>b>>c>>d;
  string s;
  cin>>s;
  if(c==d){
    cout<<"No1"<<endl;
    return 0;
  }
  bool hantei=true;
  if(c<d){
    for(long long i=a-1;i<d-1;i++){
      if(s[i]=='#'&&s[i+1]=='#'){
        hantei=false;
        break;
      }
    }
  }else{
    hantei=false;
    for(long long i=b-2;i<d-1;i++){
      if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
        hantei=true;
        //cout<<i<<endl;
      }
    }
    for(long long i=a-1;i<c-1;i++){
      if(s[i]=='#'&&s[i+1]=='#'){
        //cout<<i<<endl;
        hantei=false;
        break;
      }
    }
  }
  if(hantei)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}