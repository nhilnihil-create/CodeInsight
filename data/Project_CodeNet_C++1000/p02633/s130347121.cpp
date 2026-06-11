#include<iostream>
using namespace std;

int main(){
  int x;cin>>x;
  int ans=1,cnt=x;
  while(cnt%360!=0){
    cnt+=x;
    ans++;
  }
  cout<<ans<<endl;
  return 0;
}