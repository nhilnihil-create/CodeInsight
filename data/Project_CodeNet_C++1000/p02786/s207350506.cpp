#include<iostream>

using namespace std;

int main(){
  long long h,m=1,ans=0;
  cin>>h;
  while(h){
    ans+=m;
    h/=2;
    m*=2;
  }
  cout<<ans<<endl;
}

