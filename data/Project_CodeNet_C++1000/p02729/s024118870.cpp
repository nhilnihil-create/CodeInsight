#include <iostream>
using namespace std;

int main(){
int n,m;
  int ans=0;
    cin>>n>>m;
  if(n!=0) ans+=n*(n-1)/2;
  if(m!=0) ans+=m*(m-1)/2;
  
  cout << ans <<endl;
}
