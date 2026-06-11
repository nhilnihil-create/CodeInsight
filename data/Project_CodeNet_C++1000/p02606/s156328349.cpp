#include<iostream>
using namespace std;
int main(){
  int n,m,d;
  cin>>n>>m>>d;
  int x=1,ans=0;
  while(d*x<=m){
    if(d*x>=n&&d*x<=m)
      ans++;
    x++;
  }
  cout<<ans<<endl;
}
    